#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>

#include "menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //Forward Declaration

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow *ui;
    Menu *m_menu;
    QTimer *m_timer;
    bool m_isRunning;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override; //destructor, freeing resources from system
    /*!
     * \brief Starts and Refreshes the Main Window Display Every Second
     */
    void startMainWindow();

protected:

//Functions
private slots:
    void on_Button_Menu_clicked();
    void on_Button_Exit_clicked();
    void on_Button_Right_clicked();
    void on_Button_Algorithm1_clicked();
    void on_Button_Algorithm2_clicked();
    void on_Button_Algorithm3_clicked();
    void updateMainWindow();

    void on_Button_Save_clicked();
};
#endif // MAINWINDOW_H
