#include "delete_window.h"
#include "ui_delete_window.h"

delete_window::delete_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_window)
{
    ui->setupUi(this);
}

delete_window::~delete_window()
{
    delete ui;
}
