#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

namespace Ui {
class Logout;
}

class Logout : public QDialog
{
    Q_OBJECT

public:
    explicit Logout(QWidget *parent = nullptr);
    ~Logout();

private slots:
    void on_logout_pushButton_clicked();

private:
    Ui::Logout *ui;
};

#endif // LOGOUT_H
