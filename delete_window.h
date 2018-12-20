#ifndef DELETE_WINDOW_H
#define DELETE_WINDOW_H

#include <QDialog>

namespace Ui {
class delete_window;
}

class delete_window : public QDialog
{
    Q_OBJECT

public:
    explicit delete_window(QWidget *parent = nullptr);
    ~delete_window();

private:
    Ui::delete_window *ui;
};

#endif // DELETE_WINDOW_H
