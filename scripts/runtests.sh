executable_path = "tests/build/Tests"

if [[ -x $executable_path ]]; then
    ./$executable_path
else
    echo "Tests executable does not exist."
fi