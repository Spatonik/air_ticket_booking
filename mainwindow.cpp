#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include "secondwindow.h"
#include "deletewindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!ConnectOpen())
    {
        qDebug() << db.lastError().text();
        return;
    }
    else
    {
        qDebug() << "Success!";
    }

    model = new QSqlTableModel(this, db);
    model->setTable("cities");
    model->select();
    //ui->tableView->setModel(model);
    //ui->comboBox->setModel(model);
    //ui->comboBox->setModelColumn(0);
    //ui->comboBox_2->setModel(model);
    //ui->comboBox_2->setModelColumn(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query = QSqlQuery(db);
    if(!query.exec("select * from information"))
    {
      qDebug() << query.lastError().databaseText();
      return;
    }
    while(query.next())
    {
        qDebug() << query.record();
    }
}



void MainWindow::on_zabron_clicked()
{
    SecondWindow window2;
    window2.setModal(true);
    window2.exec();
}



void MainWindow::on_pushButton_2_clicked()
{
    DeleteWindow window3;
    window3.setModal(true);
    window3.exec();
}



void MainWindow::on_pushButton_3_clicked()
{
    EditWindow window4;
    window4.setModal(true);
    window4.exec();
}
