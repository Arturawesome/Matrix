
# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(UIComponents LANGUAGES CXX)

# Включить автоматическую обработку ui-файлов
set(CMAKE_AUTOUIC ON)

# Укажите UI-файлы
set(UI_FILES mainwindow.ui)

# Добавляем UI-файлы для обработки
add_library(UIComponents STATIC ${UI_FILES} ui_dummy.cpp)

# Настройка для правильной работы с Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
target_link_libraries(UIComponents PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)


# cmake_minimum_required(VERSION 3.10)
#
# project(MatrixApp VERSION 1.0 DESCRIPTION "A Matrix Application" LANGUAGES CXX)
#
#
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_PREFIX_PATH "/usr/lib/cmake/Qt6")
#
# # Включить автоматическую обработку ui-файлов
# set(CMAKE_AUTOUIC ON)
#
# # Set the UI-files
# set(UI_FILES mainwindow.ui)
#
# # FIND THE QT6
# find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
#
# # Generation of the headers from UI
# qt_wrap_ui(UI_HEADERS ${UI_FILES})
# add_library(MatrixUILib ${UI_HEADERS})
#
# target_link_libraries(MatrixUILib Qt6::Core Qt6::Gui Qt6::Widgets)
