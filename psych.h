#ifndef PSYCH_H
#define PSYCH_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QMatrix4x4>

#include "Algorithms/Algorithm2/algorithm_2.h"
#include "Algorithms/Algorithm3/algorithm_3.h"

class Psych : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
    QOpenGLContext *m_context;
    QMatrix4x4 *m_perspective;
    Algorithm_2 *m_Algorithm2;
    Algorithm_3 *m_Algorithm3;
    int m_Algorithm;
    float m_width, m_height;

//class private by default struct public by default

public:
    Psych(QWidget *parent = nullptr);
    ~Psych() override;

    //Get

    //Set
    /*!
     * \brief setAlgorithm - Creates new Aglorithm Object To Help Initialize The Choosen Algorithm
     * \param algorithmNumber - integer number to set which Algorithm to be called
     */
    void setAlgorithm(int algorithmNumber) { m_Algorithm = algorithmNumber;}

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

};



#endif // PSYCH_H
