# Qt6 requires compiler of at least CXX17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets)
# set automoc, autouic to true, which enables all Qt autogen features

# Find includes in build dir (required for MOC)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Run Qt's MOC automatically if required
set(CMAKE_AUTOMOC ON)
# Create code for UI files
set(CMAKE_AUTOUIC ON)
# Compile resources automatically using rcc
set(CMAKE_AUTORCC ON)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# At the end, will include helper files to target, depending on Android, iOS, static Qt, WASM.
qt_add_executable(ASandbox
    ${PROJECT_SOURCES}
)

target_link_libraries(ASandbox PRIVATE Qt6::Widgets)

install(
    TARGETS ASandbox
    RUNTIME DESTINATION bin
)
