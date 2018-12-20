#include "editwindow.h"
#include "ui_editwindow.h"
#include <QMessageBox>

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::on_pushButton_Edit_clicked()
{
    MainWindow connect;
    QString _id, name, surname, otz, data_sortie, passport, fromm, too;

    _id = ui->text_id->text();
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
    qry.prepare("update information set _id = '"+_id+"', name = '"+name+"', surname = '"+surname+"', otz = '"+otz+"', data_sortie = '"+data_sortie+"', passport = '"+passport+"', fromm = '"+fromm+"', too = '"+too+"' where _id = '"+_id+"'");
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Обновление"),tr("Обновлено!"));
        connect.ConnectClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
