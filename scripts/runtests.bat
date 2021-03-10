
@echo off

set working_dir=tests
set executable_path=build\bin\Tests.exe

if exist %working_dir%\%executable_path% (
    cd %working_dir%
    call %executable_path%
) else (
    echo "Test executable does not exist."
)
