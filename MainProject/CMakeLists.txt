project(QImageViewer)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Qt5UiTools REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(../PluginSDK/Include)

set(PROJECT_UIS )
set(PROJECT_RCS mainwindow.qrc)
set(SOURCE_FILES main.cpp mainwindow.h mainwindow.cpp)

#source_group("UIS" FILES ${PROJECT_UIS}$)
set(EXECUTABLE_OUTPUT_PATH ${SRC_BINARY_DIR}/Bin)
link_directories(${SRC_BINARY_DIR}/Bin)
add_executable(QImageViewer ${SOURCE_FILES} ${PROJECT_UIS} ${PROJECT_RCS})
target_link_libraries(QImageViewer PluginSDK Qt5::Widgets)

