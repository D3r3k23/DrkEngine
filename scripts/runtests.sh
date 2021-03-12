
working_dir="tests"
executable_path="build/bin/Tests"

if [[ -f ${working_dir}/${executable_path} ]]; then
    cd $working_dir
    ./$executable_path
else
    echo "Test executable does not exist."
fi
