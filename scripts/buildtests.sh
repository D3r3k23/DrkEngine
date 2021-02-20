mkdir -p tests/build
cmake -BUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug -B tests/build
cmake --build tests/build