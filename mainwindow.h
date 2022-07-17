#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QEvent>
#include <QMouseEvent>
#include <QMenu>
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QThread>
#include <QMessageBox>
#include <QDesktopWidget>
#include "animation.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setAreaMovable(const QRect rt);
private slots:
    //槽函数要在这里定义
    void test();
    void postHelp();
    void moveToRightBottom();
private:
       Ui::MainWindow *ui;
       QMenu *m_contextMenu;
       //QAction *m_exitAction; 停用  //退出
       QAction *m_CNAction; //改变数值
       QAction *m_mvTRghtBttm;
protected:
    void keyPressEvent(QKeyEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);

    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
    bool w_moveable;
};
#endif // MAINWINDOW_H
