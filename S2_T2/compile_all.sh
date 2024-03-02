printf "Starting to compile ALL FILES"

BUILD_FOLDER=build_ninja

mkdir -p $BUILD_FOLDER

cd $BUILD_FOLDER

cmake -G Ninja ../src
cmake --build .



printf "\n ALL FILES COMPILED! \n"