#include "login.h"
#include "ui_login.h"


#include "database.h"
#include "databasefunctions.h"

#include <QMessageBox>


LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);
    ui->claveLineEdit->setEchoMode(QLineEdit::Password);

    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    db->doQuery(secuenciaDeUsuarios);


    int i, j, min_idx;

    for (i = 0; i < secuenciaDeUsuarios.size()-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < secuenciaDeUsuarios.size(); j++)
            if (secuenciaDeUsuarios[j] < secuenciaDeUsuarios[min_idx])
                min_idx = j;

        std::tuple<QString,QString,QString>  temp = secuenciaDeUsuarios[min_idx];
        secuenciaDeUsuarios[min_idx] = secuenciaDeUsuarios[i];
        secuenciaDeUsuarios[i] = temp;
    }
}

LogIn::~LogIn()
{
    delete ui;
}

