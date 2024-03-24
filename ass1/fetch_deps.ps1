$tmp_dir = "tmp"

echo "Removing old lib folder (if it exists)..."
(rm -r -force lib) 2>&1>$null

mkdir lib > $null
cd lib

echo "Fetching dependencies..."
git clone https://gitlab.cse.unsw.edu.au/COMP3421/chicken3421-package $tmp_dir
cd $tmp_dir

if($args.count -eq 0) {
  echo "Running CMake with system defaults"
  $cmake_args = "-DCMAKE_BUILD_TYPE=Default"

} else {
  echo "Running CMake with args: $args"
  $cmake_args = $args
}

cmake -S . -B $tmp_dir $cmake_args
cmake --build $tmp_dir

cd ..
cmake --install $tmp_dir/$tmp_dir --prefix .

echo "Cleaning up..."
rm -r -force $tmp_dir


