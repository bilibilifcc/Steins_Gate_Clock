#include "mainwindow.h"

using namespace std;

static int times = 0; //测试用
static int MODE = PAUSE_MODE;
Animation *a = nullptr;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    setAttribute(Qt::WA_TranslucentBackground);//背景透明

    /*-------------------------菜单代码-------------------------*/
    m_contextMenu = new QMenu;  //创建菜单
    m_CNAction = new QAction(tr("change"),this);//创建事件
    m_contextMenu->addAction(m_CNAction); //添加事件
    //connect()用作Action和函数的链接
    connect ( m_CNAction, SIGNAL ( triggered() ), this,SLOT( test() )); /* New点击事件调用test */
    /*----------------------------------------------------------*/

    a = new Animation(ui->label,ui->label_2,ui->label_3,ui->label_4,ui->label_5,ui->label_6,ui->label_7,ui->label_8,&MODE);
    a->start();
}

MainWindow::~MainWindow()
{
    //QMessageBox::StandardButton result = QMessageBox::information(NULL,"sure?","Are you sure about it?",QMessageBox::Yes | QMessageBox::No);
    delete ui;
}

//函数已弃用
/*
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
*/

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_C){
        MODE = GATE_MODE;
        //a->run(ui->label,ui->label_2,ui->label_3,ui->label_4,ui->label_5,ui->label_6,ui->label_7,ui->label_8,&MODE);
    }else if(event->key() == Qt::Key_Escape){
        exit(0);
    }else if(event->key() == Qt::Key_T){
        MODE = TIME_MODE;
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

void MainWindow::mousePressEvent(QMouseEvent *e){
    //当右键时
    if(e->button() == Qt::RightButton){
        //cout << "RightButton Clicked" << "+" << times << endl;
        //times++;
        m_contextMenu->exec(e->globalPos());    //显示菜单并使其在鼠标右击的位置出现
    }

}

void MainWindow::test(){
    cout << "nb" << endl;
}

