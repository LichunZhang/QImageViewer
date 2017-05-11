cmake_minimum_required(VERSION 2.8.11)
project(ImageTabWidget)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_MACOSX_RPATH 1)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(../../PluginSDK/Include)

set(PROJECT_UIS )
set(SOURCE_FILES ImageTabWidget.cpp ImageTabWidget.h ImageViewer.cpp ImageViewer.h)

set(LIBRARY_OUTPUT_PATH ${SRC_BINARY_DIR}/Bin/Plugins)

add_library(ImageTabWidget SHARED ${SOURCE_FILES} ${PROJECT_UIS})
target_link_libraries(ImageTabWidget PluginSDK Qt5::Widgets)