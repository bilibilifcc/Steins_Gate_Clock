#ifndef ANIMATION_H
#define ANIMATION_H

#include <QThread>
#include <QLabel>
#include <iostream>
#include <QDebug>
#include <QTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"

#define TIME_MODE       0x00
#define GATE_MODE       0x01
#define PAUSE_MODE      0x02
#define EXIT_MODE       0x03

class Animation : public QThread
{
public:
    Animation(QLabel *lab_1,QLabel *lab_2,QLabel *lab_3,QLabel *lab_4,QLabel *lab_5,QLabel *lab_6,QLabel *lab_7,QLabel *lab_8,int * RUN_MODE);
    void run();
    //void run(QLabel *lab_1,QLabel *lab_2,QLabel *lab_3,QLabel *lab_4,QLabel *lab_5,QLabel *lab_6,QLabel *lab_7,QLabel *lab_8,int * RUN_MODE);
};

#endif // ANIMATION_H
