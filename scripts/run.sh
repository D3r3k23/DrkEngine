while getopts "d" flags; do
    case "${flag}" in
        d) debug = true;;
    esac
done

if [ "$debug" = true ]; then
    build/bin/Linux/Debug/ConsoleChess.sh
else
    build/bin/Linux/Release/ConsoleChess.sh
fi

