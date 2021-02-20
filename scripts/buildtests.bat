cd ..

if not exist "build" mkdir build

if "%1" == "-d"
    cmake -DDebug=ON -B build
else
    cmake -DDebug=OFF -B build

cmake --build build