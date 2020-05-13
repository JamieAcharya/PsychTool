#ifndef ALGORITHM_3_H
#define ALGORITHM_3_H

#include <QOpenGLFunctions_4_5_Core>
#include "menu.h"
class Algorithm_3
{
    QOpenGLFunctions_4_5_Core *m_gl;
public:
    Algorithm_3(QOpenGLFunctions_4_5_Core *gl);
    ~Algorithm_3();

    void initializeAlgorithm3();
    void drawAlgorithm3();
};

#endif // ALGORITHM_3_H
