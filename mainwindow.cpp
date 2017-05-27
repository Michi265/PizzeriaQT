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


        // Set the number of columns in the tree
    ui->treeWidget->setColumnCount(2);

      // Set the headers
    ui->treeWidget->setHeaderLabels(QStringList() << "Pizza" << "Ingredienti");


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

void MainWindow::addTreeRoot(QString name, QString description){

    //QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    //QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    if(ui->b->isChecked()){
        Bufala addBufala;
        addTreeChild(treeItem, name + "", "Bufala");

    }
    if (ui->ol->isChecked()){
        Olio_Tartufato addOlio_Tartufato;
        addTreeChild(treeItem, name + "", "Olio_Tartufato");
    }
    if(ui->fp->isChecked()){
        Funghi_Porcini addFunghi_Porcini;
        addTreeChild(treeItem, name + "", "Funghi_Porcini");
    }
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
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

            }

            if (ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));


                ui->ol->update();
            }


            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));

                ui->fp->update();
            }

            if ( myPizza.pizzaname== 10){

                addTreeRoot("Margherita","");

            total += myPizza.getCost_tot();
            }

    }

        if (ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Marinara"){

            Marinara myPizza;
            myPizza.setCost_tot(myPizza.cost());


            if(ui->b->isChecked()){
                Bufala addBufala;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addBufala.getCost()));

            }
            if(ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));

            }
            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));
                //addTreeChild(treeItem, name + "", "Funghi_Porcini");
                //ui->order_list->addItem("Funghi_Porcini");
            }

            if ( myPizza.pizzaname== 8)

                addTreeRoot("Marinara","");
                total += myPizza.getCost_tot();

        }



        if (ui->list_pizza->selectedItems().at(0)->text().toStdString()=="Napoli"){
            Napoli myPizza;
            myPizza.setCost_tot(myPizza.cost());


            if(ui->b->isChecked()){
                Bufala addBufala;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addBufala.getCost()));


            }
            if(ui->ol->isChecked()){
                Olio_Tartufato addOlio_Tartufato;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addOlio_Tartufato.getCost()));

            }
            if(ui->fp->isChecked()){
                Funghi_Porcini addFunghi_Porcini;
                myPizza.setCost_tot((myPizza.getCost_tot())+(addFunghi_Porcini.getCost()));


            }
            if ( myPizza.pizzaname== 6)
                addTreeRoot("Napoli","");

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
    if(ui->treeWidget->selectedItems().size()==0){
        QMessageBox msgBox;
        msgBox.setText(" Select pizza or/and an ingredient! ");
        msgBox.exec();
    }
    else {
            QTreeWidgetItem* item = ui->treeWidget->currentItem();
            if(item->parent()==NULL){
                    QList<QTreeWidgetItem *> tmplist = item->takeChildren();



                    if (item->text(0) == "Margherita"){
                        total = total - 4;
                        ui->total->setText(QString::number(total));
                    }

                    if (item->text(0) == "Marinara"){
                        total = total - 5;
                        ui->total->setText(QString::number(total));
                    }


                    if (item->text(0) == "Napoli"){
                        total = total - 6;
                        ui->total->setText(QString::number(total));
                    }

                    for (int i = 0; i < tmplist.size() ;i++){
                        QTreeWidgetItem* tmp = tmplist.operator [](i);


                        if (tmp->text(1) == "Bufala"){
                            total = total - 2;
                            ui->total->setText(QString::number(total));
                        }

                        if (tmp->text(1) == "Olio_Tartufato"){
                            total = total - 2;
                            ui->total->setText(QString::number(total));
                        }


                        if (tmp->text(1) == "Funghi_Porcini"){
                            total = total - 3;
                            ui->total->setText(QString::number(total));
                        }
                    }
                }


                item = ui->treeWidget->currentItem();
                if(!item)return;
                int x = ui->treeWidget->indexOfTopLevelItem(item);
                if(x >= 0 && x < ui->treeWidget->topLevelItemCount())
                {
                    item = ui->treeWidget->takeTopLevelItem(x);
                   if(item)
                       delete item;
                }

            else {
                QTreeWidgetItem* tmp = ui->treeWidget->currentItem();

                if(tmp){

                    if (tmp->text(1) == "Bufala"){
                        total = total - 2;
                        ui->total->setText(QString::number(total));
                    }

                    if (tmp->text(1) == "Olio_Tartufato"){
                        total = total - 2;
                        ui->total->setText(QString::number(total));
                    }


                    if (tmp->text(1) == "Funghi_Porcini"){
                        total = total - 3;
                        ui->total->setText(QString::number(total));
                    }

                    delete item->parent()->takeChild(item->parent()->indexOfChild(item));
                }
            }
    }

}


