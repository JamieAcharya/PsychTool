#include <ctime>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug> //Debugging Functions, Remove if Release

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_menu(nullptr),
      m_isRunning(false)
{
      ui->setupUi(this);
      m_menu = new Menu(this); //child of mainwindow
      m_timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete m_timer;
    delete m_menu;
    delete ui;
}

void MainWindow::startMainWindow()
{
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateMainWindow()));
    m_timer->start(1000);
}

void MainWindow::on_Button_Menu_clicked()
{
    m_menu->exec();
    qDebug("Menu Button Clicked!");
}

void MainWindow::on_Button_Exit_clicked()
{
    if(m_isRunning == false) this->close(); //not exit(0) to prevent memory leaks and close resources correctly
}

void MainWindow::on_Button_Right_clicked()
{
    ui->Main_View->setAlgorithm(0);
    qDebug("Clear Buttton Clicked!");
}

void MainWindow::on_Button_Algorithm1_clicked()
{
    ui->Main_View->setAlgorithm(1);
    qDebug("Algorithm1 Buttton Clicked!");
}

void MainWindow::on_Button_Algorithm2_clicked()
{
    ui->Main_View->setAlgorithm(2);
    qDebug("Algorithm2 Button Clicked!");
}

void MainWindow::on_Button_Algorithm3_clicked()
{
    ui->Main_View->setAlgorithm(3);
    qDebug("Algorithm3 Button Clicked!");

}
void MainWindow::updateMainWindow()
{
    m_timer->stop();

    ui->Main_View->update();

    m_timer->start(10);
}

void MainWindow::on_Button_Save_clicked()
{
    qDebug("Save Button Clicked!");
    //QString file = QFileDialog::getSaveFileName(this, "Save as...", "OutPut", "PNG (*.png);; BMP (*.bmp);;JPEG (*.jpg *.jpeg)");
    int Width = this->width();
    int Height = this->height();
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    unsigned char *image	= (unsigned char*)malloc(sizeof(unsigned char)*Width*Height*3);
    //std::string filename = timenowtxt + "capture.bmp";
    //const char *filenamepath = "ctime(&timenow).bmp";
    char filename[80];
    int k = rand()%9999;
    //time_t now = time(0);
    //char* timeI = ctime(&now);
    sprintf(filename,"screenshot-%d.bmp",k);

    FILE *file				= fopen(filename, "wb");

    if( image!= nullptr )
    {
        if( file!= nullptr )
        {
            glReadPixels( 0, 0, Width, Height, GL_BGR_EXT, GL_UNSIGNED_BYTE, image );

            memset( &bf, 0, sizeof( bf ) );
            memset( &bi, 0, sizeof( bi ) );

            bf.bfType			= 'MB';
            bf.bfSize			= sizeof(bf)+sizeof(bi)+Width*Height*3;
            bf.bfOffBits		= sizeof(bf)+sizeof(bi);
            bi.biSize			= sizeof(bi);
            bi.biWidth			= Width;
            bi.biHeight			= Height;
            bi.biPlanes			= 1;
            bi.biBitCount		= 24;
            bi.biSizeImage		= Width*Height*3;

            fwrite( &bf, sizeof(bf), 1, file );
            fwrite( &bi, sizeof(bi), 1, file );
            fwrite( image, sizeof(unsigned char), Height*Width*3, file );

            fclose( file );
        }
        free( image );
    }
}
