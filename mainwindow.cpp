#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Margherita.h"
#include "Marinara.h"
#include "Napoli.h"
//#include "Bufala.h"
//#include "Olio_Tartufato.h"
//#include "Funghi_Porcini.h"
#include "QMessageBox"
#include "QInputDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->list_pizza->addItem("");
    ui->list_pizza->addItem("Margherita");
    ui->list_pizza->addItem("Marinara");
    ui->list_pizza->addItem("Napoli");


    //ui->comboBox->addItem("Bufala");
    //ui->comboBox->addItem("Olio_Tartufato");
    //ui->comboBox->addItem("Funghi_Porcini");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_Add_Button_clicked()
{
    if(ui->list_pizza->selectedItems().size()==0){
        QMessageBox msgBox;
        msgBox.setText("Choose pizza!");
        msgBox.exec();
    }else{

        if(ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Margherita"){
             Margherita myPizza;
             if(ui->b->isEnabled()){
                Bufala addBufala;
               myPizza.setCost_tot(myPizza.getBasecost()+addBufala.getCost());
                ui->label_3->setText(QString::number(myPizza.cost()));
             }else
                 return;


         }
        if(ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Marinara"){
             Marinara myPizza;
             ui->label_3->setText(QString::number(myPizza.cost()));
         }
        if(ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Napoli"){
             Napoli myPizza;
             ui->label_3->setText(QString::number(myPizza.cost()));
         }
    }



}
