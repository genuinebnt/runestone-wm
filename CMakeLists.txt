cmake_minimum_required(VERSION 3.27)

project(runestone)

set(SOURCES ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 20)

find_package (glog 0.6.0 REQUIRED)
find_package(X11 REQUIRED)

add_executable(runestone ${SOURCES}/main.cpp ${SOURCES}/window_manager.cpp)

target_include_directories(runestone PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_compile_options(runestone PRIVATE -Wall -Wextra)

target_link_libraries(runestone glog::glog X11)