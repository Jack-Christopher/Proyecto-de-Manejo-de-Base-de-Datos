#ifndef CONTROLPRODUCTOSFORM_H
#define CONTROLPRODUCTOSFORM_H

#include <QWidget>
#include <QMdiSubWindow>

#include "producto.h"
#include "databasefunctions.h"

namespace Ui {
class ControlProductosForm;
}

class QSqlTableModel;

//La clase ControlProductosForm hereda de QWidget (tipo de dato de QT)
class ControlProductosForm : public QWidget
{
    Q_OBJECT

public:
    //Método públicos
    explicit ControlProductosForm(QWidget *parent = nullptr);
    int getFilaID();
    void configurarTabla();
    ~ControlProductosForm();

private slots:
    //Métodos que son ejecutados al interactuar con las interfaces
    void on_pushButtonEliminarP_clicked();

    void on_pushButtonVenderP_clicked();

    void on_tableViewProductos_clicked(const QModelIndex &index);

private:
    //Datos miembros privados
    Ui::ControlProductosForm *ui;
    QSqlTableModel *modeloProducto;  //punteros
    int filaID;
    Producto p1;
    DataBaseFunctions dbf;
};

#endif // CONTROLPRODUCTOSFORM_H
