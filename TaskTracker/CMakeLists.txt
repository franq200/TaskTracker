set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


cmake_minimum_required(VERSION 3.16)
project(TaskTracker LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(SOURCES
    src/main.cpp
    src/tasktracker.cpp
    src/sessionTimer.cpp
)

set(UI_FILES
    ui/tasktracker.ui
)

set(INCLUDES
    include/tasktracker.h
    include/sessionTimer.h
)

include_directories(
    include/
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${UI_FILES} ${INCLUDES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

enable_testing()
add_subdirectory(tests)

