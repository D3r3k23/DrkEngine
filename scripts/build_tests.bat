@echo OFF

if "%1" == ""          set "build_type=Debug"
if "%1" == "--debug"   set "build_type=Debug"
if "%1" == "-D"        set "build_type=Debug"
if "%1" == "--release" set "build_type=Release"
if "%1" == "-R"        set "build_type=Release"

set "build_dir=test\build"
set "generator=Visual Studio 16 2019"

echo Configuring CMake
cmake -S . -B %build_dir% -G %generator% -D BUILD_TESTS=ON @REM # -D CMAKE_BUILD_TYPE=%build_type%
if NOT %errorlevel% == 0 exit /b 1

echo Building Tests
cmake --build test\build --config %build_type%
if NOT %errorlevel% == 0 exit /b 1
