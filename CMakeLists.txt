cmake_minimum_required(VERSION 3.10)

# Ustaw projekt
project(QtApp LANGUAGES CXX)

# Ustaw standard C++
set(CMAKE_CXX_STANDARD 17)

# Znajd? Qt
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/qt5")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Pliki ?r?d?owe
set(SOURCES main.cpp)

# Tworzenie aplikacji
add_executable(${PROJECT_NAME} ${SOURCES})

# Powi?zanie z Qt
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
