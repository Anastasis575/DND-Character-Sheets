import os
from typing import Optional

import yaml

YAML_TYPE: str = "type"
__error: bool = False
HEADER_COMMENT: str = "/*File generated automatically by auto_enum.py " \
                      "https://github.com/dimits-exe/CppAutomationTools*/ "


class Code:
    def __init__(self, original: str = ""):
        self.output = original + "\n"
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


def import_yaml_file(input_file_path: str) -> dict:
    with open(input_file_path, "r") as stream:
        return yaml.safe_load(stream)


def write_to_file(contents: str, file_name: str, directory: str) -> None:
    if __error:
        print("Fatal error: " + file_name)
    else:
        with open(os.path.join(directory, file_name), "w+") as stream:
            stream.write(contents)


def group_type(file_contents) -> str:
    name: Optional[str] = file_contents[0]
    gr_type: Optional[str] = file_contents[1][YAML_TYPE].lower()

    if gr_type is None:
        raise AttributeError("No type specified for group " + name if name is not None else " <no name specified>")

    return gr_type


def error(e: Exception):
    global __error
    __error = True
    print("Error: ", str(e))


def warning(message: str):
    print("Warning: ", message)


def error_occurred() -> bool:
    return __error
