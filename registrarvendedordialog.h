#ifndef REGISTRARVENDEDORDIALOG_H
#define REGISTRARVENDEDORDIALOG_H

#include <QDialog>
#include "vendedor.h"
#include "administrador.h"

namespace Ui {
class RegistrarVendedorDialog;
}

// Interfaz que sirve para poder introducir los
// que se van a registrar
class RegistrarVendedorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrarVendedorDialog(QWidget *parent = nullptr);
    ~RegistrarVendedorDialog();
    Vendedor getVendedor() const {return v1;}
    Administrador getAdministrador() const {return admin;}

private slots:
    void on_buttonBoxRegistrar_accepted();

    void on_buttonBoxRegistrar_rejected();

private:
    Ui::RegistrarVendedorDialog *ui;
    Vendedor v1;
    Administrador admin;
};

#endif // REGISTRARVENDEDORDIALOG_H
