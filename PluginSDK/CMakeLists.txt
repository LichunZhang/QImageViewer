project(PluginSDK)
cmake_minimum_required(VERSION 2.8.11)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_MACOSX_RPATH 1)

include_directories(Include)

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

set(Project_HDRS
        Include/PluginOperation.h
        Include/PlatformResources.h
        Include/Splash.h)

set(Project_SRCS
        Src/PlatformResources.cpp
        Src/PluginOperation.cpp
        Src/Splash.cpp
        )

add_library(PluginSDK SHARED
        ${Project_HDRS}
        ${Project_SRCS})

set(LIBRARY_OUTPUT_PATH ${SRC_BINARY_DIR}/Bin)
target_link_libraries(PluginSDK Qt5::Widgets)

