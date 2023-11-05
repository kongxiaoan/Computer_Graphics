cmake_minimum_required(VERSION 3.26)
project(Maike_opengl)

set(CMAKE_CXX_STANDARD 17)


#设置一些OpenGL头文件所在目录的宏
set(GLEW_H /usr/local/Cellar/glew/2.2.0/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include/GLFW)
set(GLAD_H /usr/local/include/)
set(GLAD_H /usr/local/include/glad)
set(KH_H /usr/local/include/KHR)

set(GLM_INCLUDE_DIR /usr/local/Cellar/glm/0.9.9.8/include/glm)

#包含上述头文件所在目录
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${KH_H} ${GLM_INCLUDE_DIR})

#设置OpenGL库所在位置，并链接
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})


add_executable(Maike_opengl main.cpp
        src/Main.cpp
        src/Main.h
        src/simple/Triangle.cpp
        src/simple/Triangle.h
        src/utils/Shader.h
        include/glad.c)
