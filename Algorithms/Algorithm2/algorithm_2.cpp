#include "algorithm_2.h"

static float change;
static float zAxis;

Algorithm_2::Algorithm_2(QOpenGLFunctions_4_5_Core *gl) :
    m_gl(gl),
    m_program(nullptr),
    m_object1_VAO(new QOpenGLVertexArrayObject),
    m_positionBuffer(new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer)),
    m_colourBuffer(new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer)),
    m_indexBuffer(new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer)),
    m_position(0),
    m_colour(0),
    m_mvp(0),
    m_degrees(0.0f)
{
}

Algorithm_2::~Algorithm_2()
{
    delete m_program;
    m_object1_VAO->destroy();
    m_positionBuffer->destroy();
    m_colourBuffer->destroy();
    m_indexBuffer->destroy();
}
void Menu::on_spinbox_VarOne_Algo2_valueChanged(double spinbox_VarOne_Value)
{
    change = float(spinbox_VarOne_Value);
}
void Menu::on_spinbox_zValue_Algo2_valueChanged(double zValue)
{
    zAxis = float(zValue);
}
void Algorithm_2::initializeAlgorithm2()
{
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "Algorithm_2.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "Algorithm_2.frag");
    m_program->link();
    m_program->bind();

    m_position = m_program->attributeLocation("position");
    m_colour = m_program->attributeLocation("colour");
    m_mvp = m_program->uniformLocation("u_mvp");

    GLfloat verts[] =
        {
            0.5f,  0.5f, -1.0f,
           -0.5f,  0.5f, -1.0f,
           -0.5f, -0.5f, -1.0f,
            0.5f, -0.5f, -1.0f
        };

    GLfloat colours[] =
    {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };
    // Vertex Array Object
    m_object1_VAO->create();
    m_object1_VAO->bind();

    // Vertex Buffer Object
    //m_gl->glGenBuffers(1, &m_vertexBufferID);
    //m_gl->glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
    //m_gl->glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    m_positionBuffer->create();
    m_positionBuffer->bind();
    m_positionBuffer->allocate(verts, sizeof (verts));

    m_program->enableAttributeArray(m_position);
    m_program->setAttributeBuffer(m_position, GL_FLOAT, 0, 3, 0);

    m_colourBuffer->create();
    m_colourBuffer->bind();
    m_colourBuffer->allocate(colours, sizeof(colours));

    m_program->enableAttributeArray(m_colour);
    m_program->setAttributeBuffer(m_colour, GL_FLOAT, 0, 4, 0);

    GLuint index[] =
    {
        0, 1, 2,
        2, 3, 0

    };

    // Index Buffer Object
    m_indexBuffer->create();
    m_indexBuffer->bind();
    m_indexBuffer->allocate(index, sizeof(index));

    m_object1_VAO->release();
    m_indexBuffer->release();
    m_colourBuffer->release();
    m_positionBuffer->release();
    m_program->release();
}

void Algorithm_2::drawAlgorithm2(QMatrix4x4 projection)
{
    QMatrix4x4 view;
    QMatrix4x4 model;

    m_full_Matrix.setToIdentity();
    view.setToIdentity();
    model.setToIdentity();
    ///*****////
    m_degrees += change;
    model.translate(0.0f, 0.0f, zAxis);
    model.rotate(m_degrees, 0, 0, -m_degrees);


    ///*****////




    m_program->bind();
    m_object1_VAO->bind();

    m_full_Matrix = projection * view * model; //View Model

    //m_gl->glEnableVertexAttribArray(0);

    m_program->setUniformValue(m_mvp, m_full_Matrix);

    m_gl->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    m_object1_VAO->release();
    m_program->release();
}



