#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}



void SecondWindow::on_pushButton_clicked()
{
    MainWindow connect;
    QString _id, name, surname, otz, data_sortie, passport, fromm, too;
    name = ui->text_name->text();
    surname = ui->text_surname->text();
    otz = ui->text_otz->text();
    data_sortie = ui->text_data_sortie->text();
    passport = ui->text_passport->text();
    fromm = ui->text_fromm->text();
    too = ui->text_too->text();

    if(!connect.ConnectOpen())
    {
        qDebug() << "Failed!";
    }

    connect.ConnectOpen();

    QSqlQuery qry;
    qry.prepare("insert into information (name, surname, otz, data_sortie, passport, fromm, too) values ('"+name+"','"+surname+"','"+otz+"','"+data_sortie+"','"+passport+"','"+fromm+"','"+too+"')");
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Сохранение"),tr("Сохранено!"));
        connect.ConnectClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
