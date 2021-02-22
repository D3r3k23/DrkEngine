
build_dir="tests/build"

mkdir -p $build_dir
cmake -DBUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -B $build_dir
cmake --build $build_dir
