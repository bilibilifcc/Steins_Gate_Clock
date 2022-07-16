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
private slots:
    void test();
private:
       Ui::MainWindow *ui;
       QMenu *m_contextMenu;
       //QAction *m_exitAction; 停用  //退出
       QAction *m_CNAction; //改变数值
protected:
    void keyPressEvent(QKeyEvent *);
    int randNumber(int min,int max);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
};
#endif // MAINWINDOW_H
