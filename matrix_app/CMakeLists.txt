cmake_minimum_required(VERSION 3.16)

# Название проекта
project(QtApp LANGUAGES CXX)

# Настройки для работы с Qt
set(CMAKE_AUTOMOC ON)  # Автоматическая генерация MOC-файлов
set(CMAKE_AUTOUIC ON)  # Автоматическая обработка UI-файлов
set(CMAKE_AUTORCC ON)  # Автоматическая обработка ресурсов

# Найти библиотеки Qt (замените Qt6 на Qt5, если используете Qt5)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Указать исходные файлы
set(SOURCES
    main.cpp
)

# Указать заголовочные файлы, если нужно
set(HEADERS
    ../include/matrix.h
)

# Создание исполняемого файла
add_executable(QtApp ${SOURCES} ${HEADERS})

# Линковка с библиотеками Qt
target_link_libraries(QtApp PRIVATE Qt6::Widgets)

# Установить стандарт C++
set_target_properties(QtApp PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
