from typing import Any, Optional
import sys

import generator

TYPE_CONSTANTS = "constants"
NAMESPACE: str = "namespace"


class Constant:
    def __init__(self, name: str, value: Any):
        self.name = name
        self.value = value

    def is_type(self, other_type: type) -> bool:
        return isinstance(self.value, other_type)


class ConstantGroup:
    def __init__(self, name: str, namespace: Optional[str], constants: list[Constant]):
        self.name = name
        self.nested_namespaces = namespace.split("::") if namespace is not None else []
        self.constants = constants


def main(input_file_path: str, directory: str):
    try:
        file_contents = generator.import_yaml_file(input_file_path)

        constant_groups: list[ConstantGroup] = []
        for group in file_contents.items():
            if generator.group_type(group) == TYPE_CONSTANTS:
                # In case of error, keep trying to parse the rest like a normal compiler
                # The generator will refuse to produce files after we flag any error
                try:
                    constant_groups.append(parse_constant_group(group[0], group[1]))
                except Exception as exc:
                    generator.error(exc)

        for group in constant_groups:
            generator.write_to_file(generate_cpp_str(group), group.name + ".h", directory)

    except Exception as ioe:
        generator.error(ioe)


def parse_constant_group(group_name: str, group_contents: dict) -> ConstantGroup:
    name: str = group_name
    constants: list[Constant] = []
    try:
        namespace: Optional[str] = group_contents.pop(NAMESPACE)
    except KeyError:
        namespace = None

    group_contents.pop(generator.YAML_TYPE)

    for value in group_contents.items():
        constants.append(Constant(value[0].upper(), value[1]))

    return ConstantGroup(name, namespace, constants)


def generate_cpp_str(group: ConstantGroup) -> str:
    def get_cpp_definition(const: Constant) -> str:
        value: str = const.value

        if const.is_type(int):
            const_type = "int"
        elif const.is_type(str):
            const_type = "std::string"
            value = '\"' + value + '\"'
        elif const.is_type(float):
            const_type = "float"
        elif const.is_type(bool):
            const_type = "bool"
        else:
            generator.warning("No suitable type for constant {0}, string assumed".format(constant.name))
            const_type = "std::string"
            value = '\"' + value + '\"'

        return "{0} {1} = {2};".format(const_type, constant.name, value)

    code = generator.Code("#pragma once")

    code.add_statement("#include <string>")
    code.add_statement(generator.HEADER_COMMENT)
    code.add_statement()

    for namespace in group.nested_namespaces:
        code.start_block("namespace " + namespace)

    for constant in group.constants:
        code.add_statement(get_cpp_definition(constant))

    return code.to_string()


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python <program> <input file> <output directory>")
        sys.exit(-1)

    main(sys.argv[1], sys.argv[2])
    # set termination flag
    sys.exit(-1 if generator.error_occurred() else 0)