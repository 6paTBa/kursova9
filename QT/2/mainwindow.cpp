#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shortesttway.cpp"

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
    int **_matrix = createMatrix(ui->num_of_cities->text().toInt());
    QString matrixText;
    int numOfCities = ui->num_of_cities->text().toInt(),
        shortestWayStart = ui->shortest_way_start->text().toInt(),
        shortestWayFinish = ui->shortest_way_finish->text().toInt();

    for(int i=0; i < numOfCities; i++) {
        for(int j=0; j < numOfCities; j++) {
            matrixText += QString::number(_matrix[i][j]) + " ";
        }
        matrixText += '\n';
    }

    ui->matrixLabel->setText(matrixText);

    ui->result1->setText(QString::number(shortestway(_matrix, numOfCities, shortestWayStart, shortestWayFinish)));
//   ui->result1->setText(ui->num_of_cities->text());
}

void MainWindow::on_shortest_way_start_selectionChanged()
{

}

void MainWindow::on_create_matrix_btn_clicked()
{

}
