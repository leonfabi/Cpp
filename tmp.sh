SHA=$(git rev-parse HEAD)
path=$(git diff --name-only $SHA)
dir=$(dirname $path)
unique_dir=$(echo $dir | tr ' ' '\n' | sort -u | tr '\n' ' ')
echo $unique_dir
