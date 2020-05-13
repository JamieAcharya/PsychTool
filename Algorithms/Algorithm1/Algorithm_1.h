#ifndef ALGORITHM_1_H
#define ALGORITHM_1_H

#include <QtOpenGL>
static inline void Algorithm_1()
{
    glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);

        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);

        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd(); //End of graphics memory block
}

#endif // ALGORITHM_1_H
