#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/Method/PathFormat.h"
#include <QDebug>
#include "src/Hardware/Camera/CameraHelper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PathFormat lll;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Camera_clicked()
{
    int ret = CameraHelper::GetInstance()->ScanDevice();
    qDebug()<<ret;
}
