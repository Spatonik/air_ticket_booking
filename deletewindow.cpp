#include "deletewindow.h"
#include "ui_deletewindow.h"
#include <QMessageBox>
DeleteWindow::DeleteWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteWindow)
{
    ui->setupUi(this);
}

DeleteWindow::~DeleteWindow()
{
    delete ui;
}

void DeleteWindow::on_pushButton_Delete_clicked()
{
    MainWindow connect;
    QString _id, name, surname, otz, data_sortie, passport, from, to;

    _id = ui->text_id->text();
    name = ui->text_name->text();
    surname = ui->text_surname->text();
    otz = ui->text_otz->text();
    data_sortie = ui->text_data_sortie->text();
    passport = ui->text_passport->text();
    from = ui->text_from->text();
    to = ui->text_to->text();

    if(!connect.ConnectOpen())
    {
        qDebug() << "Failed!";
    }

    connect.ConnectOpen();

    QSqlQuery qry;
    qry.prepare("Delete from information where _id = '"+_id+"'");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Удаление"),tr("Удалено!"));
        connect.ConnectClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
