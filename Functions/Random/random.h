#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <cstdlib>
#include <iostream>
#include <QtOpenGL>

static std::random_device rseed;
static std::mt19937 rng(rseed());
static std::uniform_real_distribution<> XY(-10.0, 10.0);
static std::uniform_real_distribution<> WZ(-2.5, 2.5);
static std::uniform_real_distribution<> Iterations(1, 500000);
static std::uniform_real_distribution<> zAxisValue(-5, 0.9);
static std::uniform_real_distribution<> r_shapeType(0, 9);
static std::uniform_real_distribution<> r_shape_line(10, 1000);
static std::uniform_real_distribution<> r_shape_triangle(1, 50);

class Random
{
public:
    Random();
    ~Random();
    /*!
     * \brief setSeedText - Grabs the User Inputted Text From The Menu Ui
     * \param seedText - String of text which is inputted by user
     */
    void setSeedText(const QString &seedText);

    float GenerateRandomNumber();
    float getAs();
    float getStringLength();
    float getVowels();
    float getConsonants();
    /*
    QString getSeedText(Menu m)
    {
    QString get_seedText = m.m_seedText;
    return get_seedText;
    }
    */

private slots:

private:
    float number_of_a;
    float stringlength;
    float number_of_vowels;
    float number_of_consonants;
};

#endif // RANDOM_H
