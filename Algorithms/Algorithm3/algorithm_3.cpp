#include "algorithm_3.h"
static uint shapeType;
static int m_colourChoice = 0;
static float x = 0.001f, y = 0.001f,			// starting x&y values
varOne = -6.77f,
varTwo = -8.74f,
varThree = -8.69f,
varFour = -4.32f;

//static int	m_iterations = 2500; //(2^19) how many points to be drawn
static int	m_iterations = 524288;
Algorithm_3::Algorithm_3(QOpenGLFunctions_4_5_Core *gl) :
    m_gl(gl)
{
}

Algorithm_3::~Algorithm_3()
{
}

void Algorithm_3::initializeAlgorithm3()
{

}
void Menu::on_spinbox_Iterations_Algo3_valueChanged(double iterations)
{
    m_iterations = int(iterations);
}
void Menu::on_spinbox_VarOne_Algo3_valueChanged(double spinbox_varOne_Value)
{
    varOne = float(spinbox_varOne_Value);
}
void Menu::on_spinbox_VarTwo_Algo3_valueChanged(double spinbox_varTwo_Value)
{
    varTwo = float(spinbox_varTwo_Value);
}

void Menu::on_spinbox_VarThree_Algo3_valueChanged(double spinbox_varThree_Value)
{
    varThree = float(spinbox_varThree_Value);
}

void Menu::on_spinbox_VarFour_Algo3_valueChanged(double spinbox_varFour_Value)
{
    varFour = float(spinbox_varFour_Value);
}
void Menu::on_checkBox_randomColours_Algo3_stateChanged(int m_randomColours)
{
    if(m_randomColours == 2)
    {
        //setrandomcolours
        m_colourChoice = 2;
    }
    if(m_randomColours == 0)
    {
        // drawing colour currently set to green
        m_colourChoice = 0;
    }
}
void Menu::on_comboBox_shapeType_currentIndexChanged(int shapeType_index)
{
    if(shapeType_index == 0)
    {
        shapeType = GL_POINTS;
    }
    if(shapeType_index == 1)
    {
        shapeType = GL_LINES;
    }
    if(shapeType_index == 2)
    {
        shapeType = GL_LINE_STRIP;
    }
    if(shapeType_index == 3)
    {
        shapeType = GL_LINE_LOOP;
    }
    if(shapeType_index == 4)
    {
        shapeType = GL_TRIANGLES;
    }
    if(shapeType_index == 5)
    {
        shapeType = GL_TRIANGLE_STRIP;
    }
    if(shapeType_index == 6)
    {
        shapeType = GL_TRIANGLE_FAN;
    }
    if(shapeType_index == 7)
    {
        shapeType = GL_QUADS;
    }
    if(shapeType_index == 8)
    {
        shapeType = GL_QUAD_STRIP;
    }
    if(shapeType_index == 9)
    {
        shapeType = GL_POLYGON;
    }
    qDebug() << shapeType_index;
}

void Algorithm_3::drawAlgorithm3()
{
    // background colour set to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // drawing colour currently set to green
    glColor4f(0.0f, 0.7f, 0.2f, 0.3f);
    // smooth/raterization/blending techniques applied
    glEnable(GL_AMBIENT);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glRasterPos4f(0.9f, 0.0f, 0.2f, 0.1f);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // set size of point
    glPointSize(1.0f);
    glLineWidth(2.0f);

    // Indicates the buffers currently enabled for color writing.
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glScalef(0.3f,0.3f,0.0f);
    // setup drawing points loop
    glBegin(shapeType);
    // draw one point for each iteration
    for (int i = 0; i < m_iterations; i++) {
        if(m_colourChoice == 0)
        {
        // drawing colour currently set to green
            glColor4f(0.0f, 0.7f, 0.2f, 0.3f);
        } if(m_colourChoice == 2)
        {
            glColor4ub(rand()%255, rand()%255, rand()%255, 33);
        }
        // calculate point with attractor equation
        float xnew = sin(varOne * y) - cos(varTwo * x);
        float ynew = sin(varThree * x) - cos(varFour * y);

        x = xnew;
        y = ynew;
        // drawing one point at calculated x,y position
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}



