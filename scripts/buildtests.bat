
@echo off

set build_dir=tests\build

if not exist %build_dir% (
    mkdir %build_dir%
)
cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -S %cd% -B %build_dir% -G "MinGW Makefiles"
cmake --build %build_dir%

xcopy -y %build_dir%\compile_commands.json .vscode
