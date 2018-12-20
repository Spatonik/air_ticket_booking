#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

private slots:

    void on_pushButton_Edit_clicked();

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
