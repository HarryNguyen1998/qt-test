cmake_minimum_required(VERSION 3.12)

project(ASandbox VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

qt_add_executable(ASandbox
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

#add_library(ASandbox-API SHARED
#    mainwindow.cpp
#    mainwindow.h)

target_link_libraries(ASandbox PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

qt_finalize_executable(ASandbox)
