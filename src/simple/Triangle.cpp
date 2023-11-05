//
// Created by 孔平安 on 2023/11/5.
//

#include "Triangle.h"

#include <memory>


float *Triangle::getVertexData() {
    const float triangle[] = {
// ---- 位置 ----
            -0.5f, -0.5f, 0.0f, // 左下
            0.5f, -0.5f, 0.0f, // 右下
            0.0f, 0.5f, 0.0f // 正上
    };
    int size = sizeof(triangle) / sizeof(float);
    float *vertexData = new float[size];

    for (int i = 0; i < size; i++) {
        vertexData[i] = triangle[i];
    }
    return vertexData;
}

void Triangle::draw() {
    std::unique_ptr shader = std::make_unique<Shader>("../res/simple/vertex_shader_source.vert",
                                                      "../res/simple/fragment_shader_source.frag");

    while (!glfwWindowShouldClose(window)) {
        // input
        // -----
        shader->use();
        // 绘制三角形
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

