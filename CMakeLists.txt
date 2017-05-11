PROJECT(SRC)
cmake_minimum_required(VERSION 2.8.11)
#set(CMAKE_MACOSX_RPATH 1)


add_subdirectory(PluginSDK)
add_subdirectory(PluginDev/ImageIO)
add_subdirectory(PluginDev/ImageTabWidget)
add_subdirectory(MainProject)