//
// Created by 孔平安 on 2023/11/5.
//

#ifndef MAIKE_OPENGL_MAIN_H
#define MAIKE_OPENGL_MAIN_H

#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include <memory>
#include "utils/Shader.h"

class Main {
public:
    Main() {
    }

    /**
     * 创建窗口
     * @param screenWidth 宽
     * @param screenHeight 高
     * @param windowName 名称
     * @return 创建结果
     */
    virtual int createWindow(int screenWidth, int screenHeight, const char *windowName);

    /**
     * 数据处理
     */
    virtual void dataProcessing();

    virtual float *getVertexData() = 0;

    virtual void draw() = 0;

    GLuint VAO, VBO;
    GLFWwindow *window;
private:
    GLuint EBO;

};


#endif //MAIKE_OPENGL_MAIN_H
