#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_shortest_way_bttn_clicked()
{
   ui->result1->setText(ui->num_of_cities->text());
}

void MainWindow::on_shortest_way_start_selectionChanged()
{

}
