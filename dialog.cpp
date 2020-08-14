#include "dialog.h"
#include "ui_dialog.h"

#include "database.h"
#include "databasefunctions.h"

#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // Establece que no se vea la contraseña mientras es escrita
    ui->claveLineEdit->setEchoMode(QLineEdit::Password);


    // Crea una conexion a la base de datos y alamcena los datos en un vector
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());
    DataBase *db = DataBase::getInstance(nombreDeConexion);
    db->doQuery(secuenciaDeUsuarios);


    // Ordena los usuarios del vector
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

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::saludar()
{
    QMessageBox::information(this, " ", "¡Bienvenido!");
}

void Dialog::on_buttonBoxLogin_accepted()
{

    bool isAdministrador = ui->checkBoxIsAdmin->checkState();

    QString nombre = ui->usuarioLineEdit->text();
    QString clave =  ui->claveLineEdit->text();
    QString privilegios = (isAdministrador)?("Administrador"):("No Administrador");

    std::tuple<QString,QString,QString> usuario = std::make_tuple (nombre, clave, privilegios);

    // Realiza la búsqueda del usuario en el vector
    bool  LoginOK = std::binary_search( std::begin(secuenciaDeUsuarios), std::end(secuenciaDeUsuarios), usuario);

    if (LoginOK)
    {
        (privilegios == "Administrador")?(isAdmin = true):(isAdmin = false);

        saludar();
    }
    else
    {
        QMessageBox::warning(this, "Aviso", "El nombre de usuario o la contraseña son incorrectos" );
        return;
    }


    accept();
}

void Dialog::on_buttonBoxLogin_rejected()
{
    reject();
}

bool Dialog::getIsAdmin()
{
    return isAdmin;
}

