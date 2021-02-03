mkdir -p build

if [$1 == debug] then
    cmake -DDebug=ON -B build
else
    cmake -B build
fi

cmake --build build
