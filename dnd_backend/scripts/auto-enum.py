import os.path
import sys
import yaml
from typing import Optional, Any

YAML_TYPE: str = "type"
TYPE_ENUM = "enum"
DETAILS_NAMESPACE: str = "details_namespace"
NAMESPACE: str = "namespace"
VALUES: str = "values"

HEADER_COMMENT: str = "/*File generated automatically by auto-enum.py" \
                      "https://github.com/dimits-exe/CppAutomationTools*/ "


class Enum:
    def __init__(self, name: str, values: list[str], namespace: str = None, details_namespace: str = None):
        self.name = name
        self.namespace = namespace
        self.details_namespace = details_namespace
        self.values = values

    def set_name(self, name: str):
        if name is None or name.isspace():
            raise ValueError("Enum provided with no name. Please check that all enums have an appropriate name.")
        self.name = name

    def set_values(self, values: list[str]):
        if values is None or len(values) == 0:
            raise ValueError("No values provided for enum " + self.name)
        self.values = values


class Code:
    def __init__(self, original: str = ""):
        self.output = original
        self.indentation = 0

    def start_block(self, statement: str) -> None:
        self.add_statement(statement + " {")
        self.indentation += 1

    def end_block(self, statement_end: bool = False) -> None:
        self.indentation -= 1
        self.add_statement("}" + (";" if statement_end else ""))

    def add_statement(self, statement: str = "") -> None:
        self.output += self.indentation * "\t" + statement + "\n"

    def to_string(self) -> str:
        while self.indentation > 0:
            self.end_block()
        return self.output


def main(input_file_path: str, directory: str):
    try:
        with open(input_file_path, "r") as stream:
            file_contents: dict = yaml.safe_load(stream)

            enums: list[Enum] = []
            for enum_contents in file_contents.items():
                enums.append(parse_enum(enum_contents[0], enum_contents[1]))

            for enum in enums:
                if enum is not None:
                    print("Producing files for enum " + enum.name + "...")
                    write_to_file(generate_header_str(enum), enum.name + ".h", directory)
                    write_to_file(generate_source_str(enum), enum.name + ".cpp", directory)

    except IOError as ioe:
        error(ioe)
    except yaml.YAMLError as ye:
        error(ye)


def parse_enum(enum_name: str, enum_descr: Any) -> Optional[Enum]:
    name: str = enum_name
    e_dict: dict[str] = enum_descr

    # instruct caller to ignore non-enums
    if e_dict[YAML_TYPE] != TYPE_ENUM:
        return None

    if name is None or name.isspace():
        raise ValueError("Enum provided with no name. Please check that all enums have an appropriate name.")

    namespace: str = e_dict[NAMESPACE]
    details_namespace: str = e_dict[DETAILS_NAMESPACE]
    values: list[str] = e_dict[VALUES]

    if namespace is None:
        warning("No namespace provided for enum {0}, assuming global namespace.".format(name))

    if details_namespace is None:
        warning("No namespace provided for the details of enum {0}, assuming enum definition namespace.".format(name))

    return Enum(name, values, namespace, details_namespace)


def cpp_map_def(enum: Enum) -> str:
    return "const std::unordered_map<{0}, std::string> {1}".format(enum.name, cpp_map_name(enum))


def cpp_map_name(enum: Enum) -> str:
    return enum.name.upper() + "_MAP"


def cpp_qualified_name(enum: Enum) -> str:
    return "{0}::{1}".format(enum.namespace if enum.namespace is not None else "", enum.name)


def cpp_access_func_def(enum: Enum) -> str:
    return "std::string {0}ToString({1} {0})".format(enum.name.lower(), cpp_qualified_name(enum))


def cpp_iter_func_def(enum: Enum) -> str:
    return "std::vector<{0}> {1}_VALUES()".format(enum.name, enum.name.upper())


def generate_header_str(enum: Enum) -> str:
    code = Code()

    in_namespace: bool = enum.namespace is not None
    uses_details_namespace: bool = enum.details_namespace is not None

    code.add_statement("#pragma once")
    code.add_statement(HEADER_COMMENT)
    code.add_statement("#include <unordered_map>")
    code.add_statement()

    if in_namespace:
        code.start_block("namespace " + enum.namespace)

    code.start_block("enum class " + enum.name)

    for value in enum.values:
        code.add_statement(value + ",")

    code.end_block(True)
    code.add_statement()

    code.add_statement()
    code.add_statement(cpp_access_func_def(enum) + ";")
    code.add_statement()

    code.add_statement()
    code.add_statement(cpp_iter_func_def(enum) + ";")
    code.add_statement()

    if uses_details_namespace:
        code.start_block("namespace " + enum.details_namespace)

    code.add_statement("extern {0};".format(cpp_map_def(enum)))

    return code.to_string()


def generate_source_str(enum: Enum) -> str:
    # since the functions are declared outside the 'details' namespace, we may need to add the namespace prefix
    def cpp_qualified_map_name():
        map_namespace = (enum.details_namespace + "::") if enum.details_namespace is not None else ""
        return map_namespace + cpp_map_name(enum)

    code = Code()

    in_namespace: bool = enum.namespace is not None
    uses_details_namespace: bool = enum.details_namespace is not None

    code.add_statement("#include \"{0}.h\"".format(enum.name))
    code.add_statement("#include <string>")
    code.add_statement("#include <utility>")
    code.add_statement("#include <algorithm>")
    code.add_statement()

    if in_namespace:
        code.start_block("namespace " + enum.namespace)

    code.add_statement()
    code.start_block(cpp_access_func_def(enum))
    code.add_statement("return {0}.find({1})->second;".format(cpp_qualified_map_name(), enum.name.lower()))
    code.end_block()
    code.add_statement()

    code.start_block(cpp_iter_func_def(enum))
    code.add_statement("std::vector<{0}> v;".format(cpp_qualified_name(enum)))
    code.start_block("for each (auto it in {0})".format(cpp_qualified_map_name()))
    code.add_statement("v.push_back(it.first);")
    code.end_block()
    code.add_statement("return v;")
    code.end_block()
    code.add_statement()

    if uses_details_namespace:
        code.start_block("namespace " + enum.details_namespace)

    code.add_statement(cpp_map_def(enum) + " = ")

    code.start_block("")
    for value in enum.values:
        code.add_statement("std::make_pair({0}::{1}, \"{2}\"),".format(enum.name, value, value.capitalize()))
    code.end_block(True)

    return code.to_string()


def write_to_file(contents: str, file_name: str, directory: str) -> None:
    with open(os.path.join(directory, file_name), "w+") as stream:
        stream.write(contents)


def error(e: Exception):
    print("Error while parsing: ", e)


def warning(message: str):
    print("Warning: ", message)


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python <program> <input file> <output directory>")
        sys.exit(-1)

    main(sys.argv[1], sys.argv[2])
