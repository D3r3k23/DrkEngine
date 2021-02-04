if [[ $1 = "-d" ]]; then
    debug=true
fi

if [[ "$debug" = true ]]; then
    executable_path="build/bin/Linux/Debug/ConsoleChess"
else
    executable_path="build/bin/Linux/Release/ConsoleChess"
fi

if [[ -x $executable_path ]]; then
    echo "Running executable: $executable_path."
    $executable_path # Run executable
else
    echo "Executable: $executable_path does not exist."
fi