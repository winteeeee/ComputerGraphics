cmake_minimum_required(VERSION 3.24)
project(ComputerGraphics)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputerGraphics StanfordBunny.cpp main.cpp 과제1/AnalogWatch.cpp)

target_link_libraries(ComputerGraphics ${OPENGL_LIBRARIES})
target_link_libraries(ComputerGraphics ${GLUT_LIBRARIES})
target_link_libraries(ComputerGraphics -lopengl32 -g -lfreeglut)
