#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    bool ConnectOpen()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:\\SQLiteDatabaseBrowserPortable\\Data\\database.db3");

        if(!db.open())
        {
            qDebug() << db.lastError().text();
            return false;
        }
        else
        {
            qDebug() << ("Success!");
            return true;
        }
    }
    void ConnectClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_zabron_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel* model;
};

#endif // MAINWINDOW_H
