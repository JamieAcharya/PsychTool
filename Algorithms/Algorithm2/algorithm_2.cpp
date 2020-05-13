#include "algorithm_2.h"

Algorithm_2::Algorithm_2(QOpenGLFunctions_4_5_Core *gl) :
    m_gl(gl),
    m_program(nullptr),
    m_positionBuffer(new QOpenGLBuffer),
    m_position(0)
{
}

Algorithm_2::~Algorithm_2()
{
    delete m_program;
    m_positionBuffer->destroy();
}

void Algorithm_2::initializeAlgorithm2()
{
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "basic.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "basic.frag");
    m_program->link();
    m_program->bind();


    m_position = m_program->attributeLocation("position");

    //m_gl->glGenBuffers(1, &m_vertexBufferID);
    m_positionBuffer->create();
    //m_gl->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
    m_positionBuffer->bind();
    float verts[] =
        {
            0.0f,  1.0f,  0.0f,
           -1.0f, -1.0f, 0.0f,
            1.0f,  -1.0f, 0.0f
        };

    //m_gl->glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    m_positionBuffer->allocate(verts, sizeof (verts));

    m_positionBuffer->release();
    m_program->release();
}

void Algorithm_2::drawAlgorithm2()
{
    m_positionBuffer->bind();
    m_program->bind();

    //m_gl->glEnableVertexAttribArray(0);
    m_program->enableAttributeArray(m_position);

    //m_gl->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,nullptr);
    m_program->setAttributeBuffer(m_position, GL_FLOAT, 0, 3, 0);

    m_gl->glDrawArrays(GL_TRIANGLES,0,3);

    m_program->disableAttributeArray(m_position);
    m_program->release();
    m_positionBuffer->release();
}



