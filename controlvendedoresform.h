#ifndef CONTROLVENDEDORESFORM_H
#define CONTROLVENDEDORESFORM_H

#include <QWidget>

namespace Ui {
class ControlVendedoresForm;
}

class QSqlTableModel;

//La clase ControlVendedoresForm hereda de QWidget (tipo de dato de QT)
class ControlVendedoresForm : public QWidget
{
    Q_OBJECT

public:
    //Método públicos
    explicit ControlVendedoresForm(QWidget *parent = nullptr);
    void configurarTabla();
    int getFilaID();
    //Método para cambiar los privilegios de un usuario
    static void givePrivilegios(int fila);
    static void removePrivilegios(int fila);

    ~ControlVendedoresForm();

private slots:
    //Métodos que son ejecutados al interactuar con las interfaces
    void on_pushButtonEliminarU_clicked();

    void on_pushButtonCambiarPrivilegios_clicked();

    void on_tableViewVendedor_clicked(const QModelIndex &index);

private:
    //Datos miembros privados
    Ui::ControlVendedoresForm *ui;
    QSqlTableModel *modeloVendedor;
    int filaID;
};

#endif // CONTROLVENDEDORESFORM_H
