#include "controlproductosform.h"
#include "ui_controlproductosform.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "databasefunctions.h"
#include "database.h"

// Inicialización de los datos con valores por defecto
ControlProductosForm::ControlProductosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlProductosForm)
{
    ui->setupUi(this);
    configurarTabla();
}

ControlProductosForm::~ControlProductosForm()
{
    delete ui;
}


// Configura las vistas de las tablas
void ControlProductosForm::configurarTabla()
{
    modeloProducto = DataBase::newtablemodel(modeloProducto,this);

    ui->tableViewProductos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewProductos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewProductos->setModel(modeloProducto);
}


void ControlProductosForm::on_pushButtonEliminarP_clicked()
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("DELETE FROM producto WHERE id ==  '%1' ").arg(filaID);

    db->doQuery(query);


    delete modeloProducto;
    configurarTabla();

}

void ControlProductosForm::on_pushButtonVenderP_clicked()
{
    Producto p = dbf(filaID);
    if (p.getNombreP() == "")
    {
        QMessageBox::warning(this, "Limite de ventas alcanzado", "No puede vender más de 15 productos");
        return;
    }

    dbf++;

    p--;
    if(p.getCantidad() > 0)
    {
        dbf(p, filaID);

        delete modeloProducto;
        configurarTabla();
    }
    else
    {
        on_pushButtonEliminarP_clicked();
    }
}

// Almacena el elemento seleccionado de la tabla para posteriores operaciones
// como eliminar o modificar
void ControlProductosForm::on_tableViewProductos_clicked(const QModelIndex &index)
{
    filaID = modeloProducto->data(index).toInt();
}


int ControlProductosForm::getFilaID()
{
    return filaID;
}
