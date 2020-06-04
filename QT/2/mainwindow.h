#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_shortest_way_bttn_clicked();

    void on_shortest_way_start_selectionChanged();

    void on_create_matrix_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
