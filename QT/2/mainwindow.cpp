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

string* MainWindow::names_of_cities()
{
    string all_cities[ui->num_of_cities];
    switch (ui->num_of_cities)
    {
        case 10: all_cities[9] = ui->name_of_city10->text();
        case 9: all_cities[8] = ui->name_of_city9->text();
        case 8: all_cities[7] = ui->name_of_city8->text();
        case 7: all_cities[6] = ui->name_of_city7->text();
        case 6: all_cities[5] = ui->name_of_city6->text();
        case 5: all_cities[4] = ui->name_of_city5->text();
        case 4: all_cities[3] = ui->name_of_city4->text();
        case 3: all_cities[2] = ui->name_of_city3->text();
        case 2: all_cities[1] = ui->name_of_city2->text();
        case 1: all_cities[0] = ui->name_of_city1->text();
            break;
        default: return NULL;
    }

    return *all_cities;
}

int MainWindow::city_from_str_to_int(string* all_cities)
{
    for(int i = 0; i < ui->num_of_cities - 1; i++){
        if(strcmp(all_cities[i], city) == 0){
            return i;
        }
    }
    return -1;
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
