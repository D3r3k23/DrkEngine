if [[ $1 == "-d" ]]; then
    debug=true
fi

mkdir -p build

if [[ "$debug" == true ]]; then
    cmake -DCMAKE_BUILD_TYPE=Debug -B build
else
    cmake -DCMAKE_BUILD_TYPE=Release -B build
fi

cmake --build build
