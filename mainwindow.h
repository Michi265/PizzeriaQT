#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Margherita.h"
#include "Marinara.h"
#include "Napoli.h"

#include "Bufala.h"
#include "Olio_Tartufato.h"
#include "Funghi_Porcini.h"
#include "QMessageBox"
#include "QInputDialog"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int total = 0;


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_Add_Button_clicked();

    void on_removeButton_clicked();

private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
