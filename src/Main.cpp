//
// Created by 孔平安 on 2023/11/5.
//

#include "Main.h"

int Main::createWindow(int screenWidth, int screenHeight, const char *windowName) {
    // 初始化GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    if (screenWidth > 0 && screenHeight > 0) {
        window = glfwCreateWindow(screenWidth, screenHeight, windowName, nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "Failed to create opengl context" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }
        glViewport(0, 0, screenWidth, screenHeight);
        dataProcessing();
        return 0;
    }
    return -1;
}

void Main::dataProcessing() {
    //auto vertex = getVertexData();
    const float vertex[] = {
// ---- 位置 ----
            -0.5f, -0.5f, 0.0f, // 左下
            0.5f, -0.5f, 0.0f, // 右下
            0.0f, 0.5f, 0.0f // 正上
    };
    std::cout << vertex << std::endl;
//生成并绑定VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 将定点数据绑定之当前默认的缓冲中
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    // 生成并绑定 VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *) 0);
    glEnableVertexAttribArray(0);
}






