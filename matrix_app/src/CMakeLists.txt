cmake_minimum_required(VERSION 3.10)

# Название проекта
project(MatrixApp  VERSION 1.0.0 LANGUAGES CXX)

# Указываем стандарт языка
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

# Подключаем Qt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
qt6_add_resources(RESOURCE_SOURCES ${RESOURCES_DIR}/icons.qrc)

# Автоматическая обработка Qt ресурсов и UI файлов
# THIS command creates ui_mainwindow.h and (in some times) ui_mainwindow.cpp files
# qt6_wrap_ui(UI_HEADERS ${UI_DIR}/mainwindow.ui)
# qt6_add_resources(RESOURCE_SOURCES ${RESOURCES_DIR}/icons.qrc)

# Основное приложение
add_executable(MatrixApp
    main.cpp
    mainwindow.cpp
    matrix.cpp
    mainwindow.ui
    ${RESOURCES_DIR}/icons.qrc
    ${RESOURCE_SOURCES}



)
#    ${UI_DIR}/mainwindow.ui

# Добавляем UI и ресурсы в основной проект
# target_sources(MatrixApp PRIVATE ${UI_HEADERS} ${RESOURCE_SOURCES})

# Связываем с необходимыми библиотеками Qt
target_link_libraries(MatrixApp Qt6::Core Qt6::Widgets Qt6::Gui)


# Устанавливаем правила установки (например, бинарник)
install(TARGETS MatrixApp DESTINATION bin)
