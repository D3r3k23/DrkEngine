mkdir -p build

if [ $1 = "-d" ]; then
    debug=true
fi

if [ "$debug" = true ]; then
    cmake -DDebug=ON -B build
else
    cmake -DDebug=OFF -B build
fi

cmake --build build