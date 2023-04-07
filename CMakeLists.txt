cmake_minimum_required(VERSION 3.23)
project(DSAPRO)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSAPRO main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/SFML-2.5.1/include)
target_link_libraries(DSAPRO sfml-system sfml-window sfml-graphics sfml-audio)
