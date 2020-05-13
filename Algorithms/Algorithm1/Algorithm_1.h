#ifndef ALGORITHM_1_H
#define ALGORITHM_1_H
#include <QtOpenGL>
#include <QtDebug>
#include "menu.h"
#include "Functions/Random/random.h"
/*!
 * \brief m_colourChoice Variable that decides if random colours should be used
 */
static int m_colourChoice = 0;
static float x = 0.001f, y = 0.001f,			// starting x&y values
varOne = 40,
varTwo = 20,
varThree = 1.5,
varFour = 1.5;

static int	iterations = 524288; //(2^19) how many points to be drawn

void Menu::on_spinbox_VarOne_valueChanged(double spinbox_varOne_Value)
{
    varOne = float(spinbox_varOne_Value);
}
void Menu::on_spinbox_VarTwo_valueChanged(double spinbox_varTwo_Value)
{
    varTwo = float(spinbox_varTwo_Value);
}
void Menu::on_spinbox_VarThree_valueChanged(double spinbox_varThree_Value)
{
    varThree = float(spinbox_varThree_Value);
}
void Menu::on_spinbox_VarFour_valueChanged(double spinbox_varFour_Value)
{
    varFour = float(spinbox_varFour_Value);
}

void Menu::on_checkBox_randomColours_stateChanged(int m_randomColours)
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
/*!
 * \brief Algorithm_1 OpenGL Algorithm
 */
static inline void Algorithm_1()
{
        // background colour set to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        if(m_colourChoice == 0)
        {
        // drawing colour currently set to green
        glColor4f(0.0f, 0.7f, 0.2f, 0.3f);
        } if(m_colourChoice == 2)
        {
        glColor4ub(rand()%255, rand()%255, rand()%255, 33);
        }
        // smooth/raterization/blending techniques applied
        glEnable(GL_AMBIENT);
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_BLEND);
        glRasterPos4f(0.9f, 0.0f, 0.2f, 0.1f);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // set size of point
        glPointSize(1.0f);

    // Indicates the buffers currently enabled for color writing.
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glScalef(0.3f,0.3f,0.0f);
        // setup drawing points loop
        glBegin(GL_POINTS);

        // draw one point for each iteration
        for (int i = 0; i < iterations; i++) {

            // calculate point with attractor equation
            float xnew = sin(y*varTwo) + varThree*sin(x*varTwo);
            float ynew = sin(x*varOne) + varFour*sin(y*varOne);
            //float xnew = 1-y+abs(x);
            //float ynew = x;
            //float xnew = sin(y*varTwo) + varThree*sin(x*varTwo) - cos(x-y * sin(varOne));
            //float ynew = sin(x*varOne) + varFour*sin(y*varOne) - cos(y-x * sin(varTwo));

            x = xnew;
            y = ynew;
            // drawing one point at calculated x,y position
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
}

#endif // ALGORITHM_1_H
