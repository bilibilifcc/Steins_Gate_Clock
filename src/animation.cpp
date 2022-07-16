#include "animation.h"

static QLabel *l1 = nullptr;
static QLabel *l2 = nullptr;
static QLabel *l3 = nullptr;
static QLabel *l4 = nullptr;
static QLabel *l5 = nullptr;
static QLabel *l6 = nullptr;
static QLabel *l7 = nullptr;
static QLabel *l8 = nullptr;
static int *MODE = nullptr;
static QTime current_time;
static int ONCE_CALL = 0;

Animation::Animation(QLabel *lab_1,QLabel *lab_2,QLabel *lab_3,QLabel *lab_4,QLabel *lab_5,QLabel *lab_6,QLabel *lab_7,QLabel *lab_8,int *RUN_MODE)
    : QThread()
{
    //传参数
    l1 = lab_1;
    l2 = lab_2;
    l3 = lab_3;
    l4 = lab_4;
    l5 = lab_5;
    l6 = lab_6;
    l7 = lab_7;
    l8 = lab_8;
    MODE = RUN_MODE;
}

void Animation::run(){
    while(*MODE != EXIT_MODE){
        for(int i=0;i<50 && *MODE == GATE_MODE;i++){
            if(ONCE_CALL == 0){
                l2->setText(".");
                ONCE_CALL++;
            }
            l1->setNum(randBetween(0,2));
            l3->setNum(randBetween(0,10));
            l4->setNum(randBetween(0,10));
            l5->setNum(randBetween(0,10));
            l6->setNum(randBetween(0,10));
            l7->setNum(randBetween(0,10));
            l8->setNum(randBetween(0,10));
            //QWidget::repaint();//每次改变要求重绘
            QThread::msleep(10);//改变一次的间隔
            //效率低下
            if(i == 49){
                *MODE = PAUSE_MODE;
            }
        }
        ONCE_CALL = 0;

        while (*MODE == TIME_MODE) {
            if(ONCE_CALL == 0){
                l3->setText(":");
                l6->setText(":");
                ONCE_CALL++;
            }
            current_time = QTime::currentTime();
            l1->setNum(current_time.hour() / 10);
            l2->setNum(current_time.hour() % 10);
            l4->setNum(current_time.minute() / 10);
            l5->setNum(current_time.minute() % 10);
            l7->setNum(current_time.second() / 10);
            l8->setNum(current_time.second() % 10);

            //节省资源占用
            QThread::msleep(1);
        }
        ONCE_CALL = 0;
        //电源优化
        //节省资源占用
        QThread::msleep(1);
        //qDebug("pausing");
    }
}
/*
void Animation::run(QLabel *lab_1,QLabel *lab_2,QLabel *lab_3
         ,QLabel *lab_4,QLabel *lab_5,
         QLabel *lab_6,QLabel *lab_7,
         QLabel *lab_8,int * RUN_MODE){
//    while(*RUN_MODE != EXIT_MODE){
//        for(int i=0;i<50 && *RUN_MODE == GATE_MODE;i++){
//            lab_1->setNum(randNumber(0,10));
//            lab_3->setNum(randNumber(0,10));
//            lab_4->setNum(randNumber(0,10));
//            lab_5->setNum(randNumber(0,10));
//            lab_6->setNum(randNumber(0,10));
//            lab_7->setNum(randNumber(0,10));
//            lab_8->setNum(randNumber(0,10));
//            //QWidget::repaint();//每次改变要求重绘
//            QThread::msleep(10);//改变一次的间隔
//        }
//    }
    for(int i=1;;i++){
        qDebug("duiduidui");
    }
}
*/

/*
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
*/
