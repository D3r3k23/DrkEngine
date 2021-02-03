while getopts "d" flags; do
    case "${flag}" in
        d) debug = true;;
    esac
done

if [ "$debug" = true ]; then
    if [ -e "build/bin/Linux/Debug/ConsoleChess.sh" ]; then
        build/bin/Linux/Debug/ConsoleChess.sh
    else
        echo "Executable is not built."
    fi
else
    if [ -e "build/bin/Linux/Release/ConsoleChess.sh" ]; then
        build/bin/Linux/Release/ConsoleChess.sh
    else
        echo "Executable is not built."
    fi
fi

