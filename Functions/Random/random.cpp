#include "random.h"

static QString m_seedText;

Random::Random()
{

}

Random::~Random()
{

}

float Random::GenerateRandomNumber()
{
    float f = 0.1f;
    return f;
}

void Random::setSeedText(const QString &seedText)
{
    m_seedText = seedText;
}
float Random::getAs()
{
    number_of_a = std::count(m_seedText.begin(), m_seedText.end(), 'a');
    return number_of_a;
}

float Random::getStringLength()
{
    return stringlength = m_seedText.length();
}

float Random::getVowels()
{
    number_of_vowels = 0;
    QString st = m_seedText;
    for(int i=0;i<m_seedText.length();i++){
    if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o'
    || st[i]=='u' || st[i]=='A' || st[i]=='E'
    || st[i]=='I' || st[i]=='O' || st[i]=='U' ){
    number_of_vowels++;
    }
    }
    return number_of_vowels;
}

float Random::getConsonants()
{
    number_of_vowels = 0;
    QString st = m_seedText;
    for(int i=0;i<m_seedText.length();i++){
    if(st[i]=='a' || st[i]=='e' || st[i]=='i' || st[i]=='o'
    || st[i]=='u' || st[i]=='A' || st[i]=='E'
    || st[i]=='I' || st[i]=='O' || st[i]=='U' ){
    number_of_vowels++;
    }
    }
    number_of_consonants = m_seedText.length() - number_of_vowels;
    return number_of_consonants;
}





