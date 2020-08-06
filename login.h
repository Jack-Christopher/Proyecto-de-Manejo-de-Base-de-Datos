#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LogIn; }
QT_END_NAMESPACE

class LogIn : public QDialog
{
    Q_OBJECT

public:
    LogIn(QWidget *parent = nullptr);
    bool getIsAdmin();
    void saludar();
    ~LogIn();

private slots:
    void on_buttonBoxLogin_accepted();

    void on_buttonBoxLogin_rejected();

private:
    Ui::LogIn *ui;
    bool isAdmin;
    QVector<std::tuple<QString,QString,QString>> secuenciaDeUsuarios;
};
#endif // LOGIN_H
