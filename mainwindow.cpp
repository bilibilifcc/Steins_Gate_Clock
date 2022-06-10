#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QThread>
#include "QWidget"
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
    cout << 10 << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//生成随机数
int MainWindow::randNumber(int min,int max){
    int rand1 = qrand() % (max - min);
    return (rand1 + min);
}

//重写keyPressEvent函数
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_C){
        //改变每个label的内容
        //通过调整i的最大值来调整时间
        for(int i=0;i<50;i++){
            ui->label->setNum(MainWindow::randNumber(0,10));
            ui->label_3->setNum(MainWindow::randNumber(0,10));
            ui->label_4->setNum(MainWindow::randNumber(0,10));
            ui->label_5->setNum(MainWindow::randNumber(0,10));
            ui->label_6->setNum(MainWindow::randNumber(0,10));
            ui->label_7->setNum(MainWindow::randNumber(0,10));
            ui->label_8->setNum(MainWindow::randNumber(0,10));
            QWidget::repaint();//每次改变要求重绘
            QThread::msleep(10);//改变一次的间隔
        }
        ui->label->setNum(MainWindow::randNumber(0,2));
    }

    if(event->key() == Qt::Key_Escape){
        exit(0);
    }
}

//重写enterEvent函数
void MainWindow::enterEvent(QEvent *){
    //setWindowFlags(Qt::Frame);
    this->setStyleSheet("background-color:rgba(244,244,244,10)");
}

void MainWindow::leaveEvent(QEvent *){
    this->setStyleSheet("background-color:rgba(244,244,244,0)");
}


