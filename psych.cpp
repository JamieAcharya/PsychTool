#include "psych.h"
#include "Algorithms/Algorithm1/Algorithm_1.h"

Psych::Psych(QWidget *parent) : QOpenGLWidget (parent),
    m_context(nullptr),
    m_perspective(nullptr),
    m_Algorithm(0),
    m_width(this->width()),
    m_height(this->height())
{
    //Empty
}

Psych::~Psych()
{
    delete m_Algorithm3;
    delete m_Algorithm2;
    delete m_perspective;
    this->makeCurrent(); //focus inside window so opengl not drawing to system or wrong widgets
    delete m_context;
}

//Protected//
void Psych::initializeGL()
{
    m_context = new QOpenGLContext(this);
    m_context->create();
    this->makeCurrent();

    m_perspective = new QMatrix4x4();

    initializeOpenGLFunctions();
    //glClearColor(0.1f, 0.07f, 0.025f, 1.0f);

    qDebug("OpenGL version (%s", glGetString(GL_VERSION));

    m_Algorithm2 = new Algorithm_2(this);
    m_Algorithm2->initializeAlgorithm2();


    m_Algorithm3 = new Algorithm_3(this);
    m_Algorithm3->initializeAlgorithm3();

}

void Psych::paintGL()
{
    this->makeCurrent();
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    if(m_Algorithm == 1)
    {
        Algorithm_1();
    }
    else if(m_Algorithm == 2)
    {
        m_Algorithm2->drawAlgorithm2(*m_perspective);
    }
    else if(m_Algorithm == 3)
    {
        m_Algorithm3->drawAlgorithm3();
    }

    //update();
}

void Psych::resizeGL(int w, int h)
{

    m_perspective->setToIdentity();
    m_width = static_cast<float>(w);
    m_height = static_cast<float>(h);

    float aspectRatio = m_width / m_height;
    m_perspective->perspective(75.0f, aspectRatio, 0.1f, 100.0f);

    //glViewport(0, 0, GLint(w), GLint(h));
}
