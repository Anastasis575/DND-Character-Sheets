::Meant to be executed from within the VS IDE

@echo off 

set main_folder=%~dp0..\
set res_dir=%main_folder%\resources
set out_dir=%main_folder%\entities

python scripts\auto_enum.py %res_dir%\enums.yml %out_dir%
python scripts\auto_constants.py %res_dir%\rules.yml %out_dir%