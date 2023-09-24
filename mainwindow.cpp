#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "QPainter"
#include "QGraphicsView"
#include "math.h"
#include "stdio.h"
#include "iostream"
float TX_Power, Ant, PL;
float f,d,max,zn,metres;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    TX_Power=81;
    Ant = 3;
    f=2.4;

    PL = 28.0 + 22 * log10(f) + 20 * log10(1);
    std::cout<<PL<<"db"<<std::endl;
    max = TX_Power + Ant - PL;
    std::cout<<max<<"db"<<std::endl;
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene();

        QPixmap map(1000, 1000); // создаем карту для рисования
        QPainter p(&map);

        for(int i = 0; i < 1000; i++){
            for(int j = 0; j < 1000; j++){

                metres = sqrt(pow(500-i,2) + pow(500-j,2));
                PL = 28.0 + 22 * log10(f) + 20 * log10(metres);
                zn = TX_Power + Ant - PL;
                //std::cout<<metres<<"m" <<std::endl;
                //std::cout<<zn<< "db"<<std::endl;
                if((zn / max) >= 0.8){
                p.setPen(QColor(3,64,255,255));

                }
                if(((zn / max) >= 0.6) && ((zn / max) < 0.8)){
                p.setPen(QColor(0,235,255,255));

                }
                if(((zn / max) >= 0.4) && ((zn / max) < 0.6)){
                p.setPen(QColor(0,255,16,255));

                }
                if(((zn / max) >= 0.2) && ((zn / max) < 0.4)){
                p.setPen(QColor(255,251,1,255));

                }
                if(((zn / max) >= 0.01) && ((zn / max) < 0.2)){
                p.setPen(QColor(255,22,0,255));

                }
                if((zn / max) <= 0.0){
                p.setPen(QColor(0,0,0,0));

                }
                    p.drawPoint(i, j);
            }
        }
        p.end();
        scene->addPixmap(map);
        QGraphicsView* view = new QGraphicsView(scene);
        setCentralWidget(view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

