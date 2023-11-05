//
// Created by 孔平安 on 2023/11/5.
//

#ifndef MAIKE_OPENGL_TRIANGLE_H
#define MAIKE_OPENGL_TRIANGLE_H

#include "../Main.h"

class Triangle : public Main {
public:
    float *getVertexData() override;

    void draw() override;
};


#endif //MAIKE_OPENGL_TRIANGLE_H
