cmake_minimum_required(VERSION 3.16)

# Название проекта
project(MatrixApp)

# Указываем стандарт языка
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Установка переменных для путей
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(UI_DIR ${CMAKE_SOURCE_DIR}/ui)
set(TESTS_DIR ${CMAKE_SOURCE_DIR}/tests)
set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/resources)

# Подключаем Qt
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# Указываем путь для включения заголовочных файлов
include_directories(${INCLUDE_DIR})

# Основное приложение
add_executable(MatrixApp
    ${SRC_DIR}/mainwindow.cpp
    ${SRC_DIR}/matrix.cpp
    ${UI_DIR}/mainwindow.ui
    ${RESOURCES_DIR}/icons.qrc
   ${SRC_DIR}/main.cpp
    ${UI_HEADERS}
    ${RESOURCE_SOURCES}
)

# Автоматическая обработка Qt ресурсов и UI файлов
# THIS command creates ui_mainwindow.h and (in some times) ui_mainwindow.cpp files
qt6_wrap_ui(UI_HEADERS ${UI_DIR}/mainwindow.ui)
qt6_add_resources(RESOURCE_SOURCES ${RESOURCES_DIR}/icons.qrc)

# Добавляем UI и ресурсы в основной проект
target_sources(MatrixApp PRIVATE ${UI_HEADERS} ${RESOURCE_SOURCES})

# Связываем с необходимыми библиотеками Qt
target_link_libraries(MatrixApp Qt6::Core Qt6::Widgets Qt6::Gui)

# Подключение тестов (если нужно)
add_subdirectory(tests)

# Устанавливаем правила установки (например, бинарник)
install(TARGETS MatrixApp DESTINATION bin)
