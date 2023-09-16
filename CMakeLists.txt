cmake_minimum_required(VERSION 3.23)
project(RetroSteam VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME               RetroSteam)
set(SERVER_PROJECT_NAME        ${PROJECT_NAME}_server)
set(SERVER_LIBRARY             ${SERVER_PROJECT_NAME}_library)
set(SERVER_TESTS_PROJECT_NAME  ${SERVER_PROJECT_NAME}_tests)
set(CLIENT_PROJECT_NAME        ${PROJECT_NAME}_client)
set(CLIENT_LIBRARY             ${CLIENT_PROJECT_NAME}_library)
set(CLIENT_TESTS_PROJECT_NAME  ${CLIENT_PROJECT_NAME}_tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui HttpServer)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui HttpServer)

set(QT_DEPENDIES
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::HttpServer
)

include_directories(server/src)

#add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(tests)
