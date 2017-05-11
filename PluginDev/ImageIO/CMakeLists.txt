cmake_minimum_required(VERSION 2.8.11)
project(ImageIO)

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
set(SOURCE_FILES ImageIO.h ImageIO.cpp)
set(PROJECT_RCS ImageIO.qrc)

set(LIBRARY_OUTPUT_PATH ${SRC_BINARY_DIR}/Bin/Plugins)

add_library(ImageIO SHARED ${SOURCE_FILES} ${PROJECT_UIS} ${PROJECT_RCS})
target_link_libraries(ImageIO PluginSDK Qt5::Widgets)