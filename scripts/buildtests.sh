
build_dir="tests/build"

mkdir -p $build_dir

cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -S . -B $build_dir && 
    if [[ -d .vscode ]]; then
        cp "${build_dir}/compile_commands.json" .vscode
    fi

cmake --build $build_dir
