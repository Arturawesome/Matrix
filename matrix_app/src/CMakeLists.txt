cmake_minimum_required(VERSION 3.10)


#The project name and standard c++
project(MatrixApp VERSION 1.0 DESCRIPTION "A Matrix Application" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")

# Set cpp files
add_executable(MatrixApp main.cpp mainwindow.cpp matrix.cpp)

# set the paths for header files
target_include_directories(MatrixApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


# switch on Qt

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
target_link_libraries(MatrixApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
