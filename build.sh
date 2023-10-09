BUILD_DIR="build/"
BUILD_TYPE="Debug"
BUILD_GENERATOR="Ninja"
TOOLCHAIN_FILE="conan_toolchain.cmake"
CONAN_PROFILE="conanprofile.toml"

mkdir -p $BUILD_DIR

conan install . --output-folder=$BUILD_DIR --profile $CONAN_PROFILE --build=missing

cd $BUILD_DIR
cmake .. -G $BUILD_GENERATOR -D CMAKE_BUILD_TYPE=$BUILD_TYPE -D CMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_FILE
cmake --build .
cd ..

