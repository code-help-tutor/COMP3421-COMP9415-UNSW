WeChat: cstutorcs
QQ: 749389476
Email: tutorcs@163.com
#! /usr/bin/env sh

tmp_dir="tmp"

echo "Removing old lib folder (if it exists)..."
rm -rf lib

mkdir lib
cd lib || exit

echo "Fetching dependencies..."
git clone https://gitlab.cse.unsw.edu.au/COMP3421/chicken3421-package ${tmp_dir}
cd ${tmp_dir} || exit

if [ $# -eq 0 ];
then
  echo "Running CMake with system defaults"
  cmake_args="-DCMAKE_BUILD_TYPE=Default"
else
  echo "Running CMake with args: $*"
  cmake_args=$*
fi

cmake -S . -B ${tmp_dir} $cmake_args
cmake --build ${tmp_dir}

cd ..
cmake --install ${tmp_dir}/${tmp_dir} --prefix .

echo "Cleaning up..."
rm -rf ${tmp_dir}
