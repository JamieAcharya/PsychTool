#ifndef ALGORITHM_2_H
#define ALGORITHM_2_H

#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Algorithm_2
{
    QOpenGLFunctions_4_5_Core *m_gl;
    QOpenGLShaderProgram *m_program;
    QOpenGLBuffer *m_positionBuffer;
    int m_position;

public:
    Algorithm_2(QOpenGLFunctions_4_5_Core *gl);
    ~Algorithm_2();

    void initializeAlgorithm2();
    void drawAlgorithm2();
};

#endif // ALGORITHM_2_H
