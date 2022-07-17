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
    m_areaMovable = geometry();//客户区
    m_bPressed = false;
    w_moveable = true;//初始设置可移动

    /*-------------------------菜单代码-------------------------*/
    m_contextMenu = new QMenu;  //创建菜单
    m_CNAction = new QAction(tr("help"),this);//创建事件
    m_mvTRghtBttm = new QAction(tr("fix on right bottom"),this);//固定在右下角
    m_contextMenu->addAction(m_CNAction); //添加事件
    m_contextMenu->addAction(m_mvTRghtBttm);
    //connect()用作Action和函数的链接
    connect ( m_CNAction, SIGNAL ( triggered() ), this,SLOT( postHelp() ) ); /* New点击事件调用test */
    connect ( m_mvTRghtBttm, SIGNAL ( triggered() ), this,SLOT( moveToRightBottom() ) );
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
    //setWindowFlags(Qt::frame);
    this->setStyleSheet("background-color:rgba(244,244,244,10)");
    //ui->centralwidget->setStyleSheet("background-color:rgba(244,244,244,10)");
}

void MainWindow::leaveEvent(QEvent *){
    this->setStyleSheet("background-color:rgba(244,244,244,0.01)");
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    //当右键时
    if(e->button() == Qt::RightButton){
        //cout << "RightButton Clicked" << "+" << times << endl;
        //times++;
        m_contextMenu->exec(e->globalPos());    //显示菜单并使其在鼠标右击的位置出现
    }else if(e->button() == Qt::LeftButton){
        //包括判断
        //e->pos()返回当前鼠标位置
        m_ptPress = e->pos();
        m_bPressed = m_areaMovable.contains(m_ptPress);
    }

}

void MainWindow::test(){
    cout << "nb" << endl;
}

void MainWindow::postHelp(){
    //cout << "nn" << endl;
    //this传入后会把CSS样式表也统一
    QMessageBox m/*(this)*/;
    m.setWindowTitle(tr("Help"));
    m.setText(tr("'C' to change figure.\n'T' to change to time mode.\n'Esc' to exit."));
    m.exec();
    //qDebug("dui");
    //QMessageBox::information(NULL,tr("Help"),tr("Press 'C' to change figure.\nPress 'T' to change to time mode."),QMessageBox::Ok);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if(m_bPressed && w_moveable == true){
        //移动
        move(pos() + e->pos() - m_ptPress);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *){
    //当松开时，isPressed = false
    m_bPressed = false;
}

//设置鼠标按下的区域
void MainWindow::setAreaMovable(const QRect rt){
    if(m_areaMovable != rt){
        m_areaMovable = rt;
    }
}

void MainWindow::moveToRightBottom(){
    //this->setGeometry();
    if(m_mvTRghtBttm->text() == tr("fix on right bottom")){
        this->move(QApplication::desktop()->availableGeometry().width() - this->geometry().width()
                   ,QApplication::desktop()->availableGeometry().height() - this->geometry().height());
        m_mvTRghtBttm->setText(tr("recover"));
        w_moveable = false;
    }else if(m_mvTRghtBttm->text() == tr("recover")){
        w_moveable = true;
        m_mvTRghtBttm->setText(tr("fix on right bottom"));
    }
}
