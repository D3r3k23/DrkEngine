build_dir="tests/build"
generator="Unix Makefiles"
compiler="g++"

echo "Configuring CMake"

cmake -S . -B $build_dir -G $generator -D CMAKE_CXX_COMPILER=$compiler -D CMAKE_BUILD_TYPE=Debug -D BUILD_TESTS=ON -D CMAKE_EXPORT_COMPILE_COMMANDS=ON
if [ $/ -ne 0 ]; then exit 1; fi

if [ -d .vscode ]; then
    cp "${build_dir}/compile_commands.json" .vscode
fi

echo "Building Tests"

cmake --build $build_dir
