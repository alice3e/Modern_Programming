printf "Starting to test HW1"



mkdir src/hw1_insertion_sort/cmake-build-debug

cd src/hw1_insertion_sort/cmake-build-debug
cmake ../CMakeLists.txt
make 
cd ../../


printf "\n HW1 COMPILED! \n"

mkdir Unit_Tests/cmake-build-debug

cd Unit_Tests/cmake-build-debug
cmake ../CMakeLists.txt
make 


printf "DONE!"
