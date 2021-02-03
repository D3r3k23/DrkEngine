mkdir -p build

while getopts "d" flags; do
    case "${flag}" in
        d) debug = true;;
    esac
done

if [ "$debug" = true ]; then
    cmake -DDebug=ON -B build
else
    cmake -B build
fi

cmake --build build
