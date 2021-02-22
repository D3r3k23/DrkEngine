executable_path = "tests/build/bin/Tests"

if [[ -x $executable_path ]]; then
    ./$executable_path
else
    echo "Test executable does not exist."
fi
