mkdir -p build

if [ $1 = "-d" ]; then
    cmake -DDebug=ON -B build
else
    cmake -DDebug=OFF -B build
fi

cmake --build build