#ifndef ALGORITHM_2_H
#define ALGORITHM_2_H

#include "menu.h"
#include <QMatrix4x4>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class Algorithm_2
{
    QOpenGLFunctions_4_5_Core *m_gl;
    QOpenGLShaderProgram *m_program;
    QOpenGLVertexArrayObject *m_object1_VAO;
    QOpenGLBuffer *m_positionBuffer;
    QOpenGLBuffer *m_colourBuffer;
    QOpenGLBuffer *m_indexBuffer;
    int m_position, m_colour, m_mvp;
    QMatrix4x4 m_full_Matrix;
    float m_degrees;

public:
    Algorithm_2(QOpenGLFunctions_4_5_Core *gl);
    ~Algorithm_2();

    void initializeAlgorithm2();
    void drawAlgorithm2(QMatrix4x4 perspective);
};

#endif // ALGORITHM_2_H
