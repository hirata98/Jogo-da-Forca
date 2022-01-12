cmake_minimum_required(VERSION 3.20)
# set the projectX name to the name of your project
project(Forca4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Forca4 main.cpp textos.cpp textos.h textbox.cpp textbox.h Buttun.cpp Buttun.h)
include_directories(C:\\SFML\\include)
link_directories(C:\\SFML\\build\\bin\\lib)
target_link_libraries(Forca4 -lsfml-System -lsfml-Window -lsfml-Graphics -lsfml-Audio)