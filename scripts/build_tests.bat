@echo OFF

set "build_dir=test\build"
set "generator=Visual Studio 16 2019"

echo Configuring CMake

cmake -S . -B "%build_dir%" -G "%generator%" -D CMAKE_BUILD_TYPE=Debug -D BUILD_TESTS=ON
if NOT %errorlevel% == 0 exit /b 1

echo Building Tests
