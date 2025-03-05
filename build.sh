BUILD_TYPE="Ninja"
SOURCE_FOLDER="homework"


cmake -G $BUILD_TYPE ./$SOURCE_FOLDERE
cmake --build .

ctest -j --output-on-failure