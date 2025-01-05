cmake_minimum_required(VERSION 3.10)

project(QtApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/qt5")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(include)

set(SOURCES
        src/main.cpp
        src/Register.cpp
        src/Customer.cpp
        src/Ticket.cpp
        src/Screening.cpp
        src/Seat.cpp
        src/CinemaManager.cpp
)

set(HEADERS
        include/Register.h
        include/Customer.h
        include/Ticket.h
        include/Group.h
        include/Concessionary.h
        include/Normal.h
        include/Normal.h
        include/Screening.h
        include/Seat.h
        include/CinemaManager.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wno-deprecated-declarations)
endif()
