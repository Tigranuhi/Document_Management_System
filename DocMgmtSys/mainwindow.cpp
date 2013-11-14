#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <Query.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    Query qr;
    qr.add_value(10);
}
