#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include "Functions/Random/random.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    QString m_seedText;

protected:
    //void setAlgo1VarOne (const float Algo1_varspinBox_1) {m_Algo1_VarOne = Algo1_varspinBox_1}
private slots:
    void on_Button_Close_clicked();

    void on_button_generate_randomNumbers_clicked();

    void on_spinbox_VarOne_valueChanged(double spinbox_varOne_Value);

    void on_spinbox_VarTwo_valueChanged(double spinbox_varTwo_Value);

    void on_spinbox_VarThree_valueChanged(double spinbox_varThree_Value);

    void on_spinbox_VarFour_valueChanged(double spinbox_varFour_Value);

    void on_checkBox_randomColours_stateChanged(int arg1);

    void on_lineEdit_randomSeed_returnPressed();

    void on_spinbox_VarOne_Algo2_valueChanged(double spinbox_VarOne_Value);

    void on_spinbox_VarOne_Algo3_valueChanged(double spinbox_varOne_Value);

    void on_spinbox_VarTwo_Algo3_valueChanged(double spinbox_varTwo_Value);

    void on_spinbox_VarThree_Algo3_valueChanged(double spinbox_varThree_Value);

    void on_spinbox_VarFour_Algo3_valueChanged(double spinbox_varFour_Value);

    void on_spinbox_Iterations_Algo3_valueChanged(double iterations);

    void on_spinbox_zValue_Algo2_valueChanged(double zValue);

    void on_comboBox_shapeType_currentIndexChanged(int shapeType_index);

    void on_checkBox_randomColours_Algo3_stateChanged(int m_randomColours);

    void on_button_generate_randomShape_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
