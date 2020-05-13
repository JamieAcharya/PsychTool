#include "menu.h"
#include "ui_menu.h"
#include <QDebug>


Menu::Menu(QWidget *parent) : QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}


void Menu::on_Button_Close_clicked()
{
    this->close();
}

/*
QString Menu::getRandomSeedText(void)
{
    return m_seedText;
}
*/

void Menu::on_lineEdit_randomSeed_returnPressed()
{
    m_seedText = ui->lineEdit_randomSeed->text(); //setting variable to Text entered within textbox
    qDebug() << "seed text: " << m_seedText; // For Testing Puporses

    Random r;
    r.setSeedText(m_seedText); //Setting variable used in text RNG
    //Algorithm 1
    ui->spinbox_VarOne->setValue(double(r.getStringLength()));
    ui->spinbox_VarTwo->setValue(double(r.getConsonants()));
    ui->spinbox_VarThree->setValue(double(r.getAs()));
    ui->spinbox_VarFour->setValue(double(r.getVowels()));
    qDebug() << "length: " << r.getStringLength();
    qDebug() << "consonants: " << r.getConsonants();
    qDebug() << "a's: " << r.getAs();
    qDebug() << "vowels: " << r.getVowels();

    //Algorithm2
    ui->spinbox_VarOne_Algo2->setValue(double(r.getStringLength()));

    //Algorithm3
    if(ui->comboBox_shapeType->currentIndex() == 0)
    {
        ui->spinbox_Iterations_Algo3->setValue(double(r.getStringLength() * 50000));
    }
    if(ui->comboBox_shapeType->currentIndex() == 1 || ui->comboBox_shapeType->currentIndex() == 2 || ui->comboBox_shapeType->currentIndex() == 3)
    {
        ui->spinbox_Iterations_Algo3->setValue(double(r.getConsonants() * 10));
    }
    if(ui->comboBox_shapeType->currentIndex() > 4 )
    {
        ui->spinbox_Iterations_Algo3->setValue(double(r.getStringLength()));
    }
    ui->spinbox_VarOne_Algo3->setValue(double(r.getStringLength()));
    ui->spinbox_VarTwo_Algo3->setValue(double(r.getConsonants()));
    ui->spinbox_VarThree_Algo3->setValue(double(r.getAs()));
    ui->spinbox_VarFour_Algo3->setValue(double(r.getVowels()));
}
void Menu::on_button_generate_randomNumbers_clicked()
{
    //Algorithm 1
    ui->spinbox_VarOne->setValue(double(XY(rng)));
    ui->spinbox_VarTwo->setValue(double(XY(rng)));
    ui->spinbox_VarThree->setValue(double(WZ(rng)));
    ui->spinbox_VarFour->setValue(double(WZ(rng)));

    //Algorithm 2
    ui->spinbox_zValue_Algo2->setValue(double(zAxisValue(rng)));
    ui->spinbox_VarOne_Algo2->setValue(double(XY(rng)));
    qDebug() << "Random Button Clicked!";
    //Algorithm 3
    //ui->comboBox_shapeType->setCurrentIndex(int(r_shapeType(rng)));
    if(ui->comboBox_shapeType->currentIndex() == 0)
    {
        ui->spinbox_Iterations_Algo3->setValue(double(Iterations(rng)));
    }
    if(ui->comboBox_shapeType->currentIndex() == 1 || ui->comboBox_shapeType->currentIndex() == 2 || ui->comboBox_shapeType->currentIndex() == 3)
    {
        ui->spinbox_Iterations_Algo3->setValue(double(r_shape_line(rng)));
    }
    if(ui->comboBox_shapeType->currentIndex() > 4 )
    {
        ui->spinbox_Iterations_Algo3->setValue(double(r_shape_triangle(rng)));
    }
    ui->spinbox_VarOne_Algo3->setValue(double(XY(rng)));
    ui->spinbox_VarTwo_Algo3->setValue(double(XY(rng)));
    ui->spinbox_VarThree_Algo3->setValue(double(XY(rng)));
    ui->spinbox_VarFour_Algo3->setValue(double(XY(rng)));
}


void Menu::on_button_generate_randomShape_clicked()
{
    ui->comboBox_shapeType->setCurrentIndex(int(r_shapeType(rng)));
}
