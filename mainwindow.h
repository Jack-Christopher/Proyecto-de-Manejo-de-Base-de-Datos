#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QVector>
#include "administrador.h"
#include "vendedor.h"
#include "dialog.h"
#include "controlproductosform.h"
#include "controlvendedoresform.h"

namespace Ui {
class MainWindow;
}


// Ventana principal de la aplicación
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    // Define los privilegios del usuario
    // De acuerdo a ésto. ciertas opciones estarán disponibles o no
    void setPrivilegios(bool isAdministrador);

    // Inserta un usuario (de tipo Vendedor o Administrador)
    template<typename Tipo>
    void insertarUsuario(Tipo *usuario);

    // Devuelve el estado en el que se encuentra la aplicación
    int getStatus();
    void closeEvent (QCloseEvent *event);
    ~MainWindow();

private slots:

    void on_actionAcerca_de_triggered();

    void on_actionMostrar_Productos_triggered();

    void on_actionRegistrar_Productos_triggered();

    void on_actionRegistrar_Usuarios_triggered();

    void on_actionMostrar_Usuarios_triggered();

    void on_actionCerrarSesion_triggered();

    void on_actionSalir_triggered();

    void on_actionModificar_Producto_triggered();

private:
    Ui::MainWindow *ui;

    int status;

    Administrador ad1;
    Vendedor d1;

    ControlProductosForm *ctrlP;
    ControlVendedoresForm *ctrlV;

    QMdiSubWindow *qmdsw;
};

#endif // MAINWINDOW_H
