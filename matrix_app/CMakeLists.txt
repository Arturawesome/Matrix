cmake_minimum_required(VERSION 3.10)


#The project name and standard c++
project(MatrixApp VERSION 1.0 LANGUAGE CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widjets)

# include and add subdirectories
add_subdirectory(src)
add_subdirectory(ui)
add_subdirectory(resources)
add_subdirectory(tests)
