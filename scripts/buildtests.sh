
build_dir="tests/build"

mkdir -p $build_dir
cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -S . -B $build_dir &&
cmake --build $build_dir &&

if [[ -f .vscode/c_cpp_properties.json ]]; then
    cp tests/build/compile_commands.json .vscode
fi
