#include "mainwindow.h"
#include <iostream>
#include "stdio.h"
#include <string>
#include "ui_mainwindow.h"
#include "Margherita.h"
#include "Marinara.h"
#include "Napoli.h"

#include "Bufala.h"
#include "Olio_Tartufato.h"
#include "Funghi_Porcini.h"
#include "QMessageBox"
#include "QInputDialog"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("/home/michela/Downloads/sfondo.jpg");
      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      this->setPalette(palette);

    ui->list_pizza->addItem("Margherita");
    ui->list_pizza->addItem("Marinara");
    ui->list_pizza->addItem("Napoli");


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
        msgBox.setText(" Choose pizza! ");
        msgBox.exec();

    }
    else{
        if (ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Margherita"){

            Margherita myPizza;
            myPizza.setCost_tot(myPizza.cost());

            if(ui->b->isChecked()){
                Bufala addBufala;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addBufala.getCost()));
                ui->order_list->addItem("Bufala");
                ui->b->update();
            }

            if (ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));
                ui->order_list->addItem("Olio_Tartufato");
                ui->ol->update();
            }


            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));
                ui->order_list->addItem("Funghi_Porcini");
                ui->fp->update();
            }

            if ( myPizza.pizzaname== 10)
                ui->order_list->addItem("Margherita");
            ui->order_list->addItem("");
            total += myPizza.getCost_tot();


    }

        if (ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Marinara"){

            Marinara myPizza;
            myPizza.setCost_tot(myPizza.cost());


            if(ui->b->isChecked()){
                Bufala addBufala;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addBufala.getCost()));
                ui->order_list->addItem("Bufala");
            }
            if(ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));
                ui->order_list->addItem("Olio_Tartufato");

            }
            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));
                ui->order_list->addItem("Funghi_Porcini");
            }

            if ( myPizza.pizzaname== 8)
                ui->order_list->addItem("Marinara");
            ui->order_list->addItem("");
            total += myPizza.getCost_tot();

        }



        if (ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Napoli"){
            Napoli myPizza;
            myPizza.setCost_tot(myPizza.cost());


            if(ui->b->isChecked()){
                Bufala addBufala;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addBufala.getCost()));
                ui->order_list->addItem("Bufala");

            }
            if(ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));
                ui->order_list->addItem("Olio_Tartufato");

            }
            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));
                ui->order_list->addItem("Funghi_Porcini");

            }
            if ( myPizza.pizzaname== 6)
                ui->order_list->addItem("Napoli");
            ui->order_list->addItem("");
            total += myPizza.getCost_tot();


        }

        ui->total->setText(QString::number(total));

        if (ui->b->isChecked()){
            ui->b->setCheckState(Qt::Unchecked);

            }
        if (ui->ol->isChecked()){
            ui->ol->setCheckState(Qt::Unchecked);

            }
        if (ui->fp->isChecked()){
            ui->fp->setCheckState(Qt::Unchecked);

            }

    }
}


void MainWindow::on_removeButton_clicked()
{
    QList<QListWidgetItem*> items = ui->order_list->selectedItems();
    foreach(QListWidgetItem* item,items){

        QListWidgetItem* tmp = ui->order_list->takeItem(ui->order_list->row(item));

        if (tmp->text() == "Margherita"){
            total = total - 4;
            ui->total->setText(QString::number(total));
        }

        if (tmp->text() == "Marinara"){
            total = total - 5;
            ui->total->setText(QString::number(total));
        }


        if (tmp->text() == "Napoli"){
            total = total - 6;
            ui->total->setText(QString::number(total));
        }
        if (tmp->text() == "Bufala"){
            total = total - 2;
            ui->total->setText(QString::number(total));
        }

        if (tmp->text() == "Olio_Tartufato"){
            total = total - 2;
            ui->total->setText(QString::number(total));
        }


        if (tmp->text() == "Funghi_Porcini"){
            total = total - 3;
            ui->total->setText(QString::number(total));
        }

        delete ui->order_list->takeItem(ui->order_list->row(item));

    }
}

