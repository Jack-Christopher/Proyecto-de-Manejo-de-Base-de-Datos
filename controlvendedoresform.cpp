#include "controlvendedoresform.h"
#include "ui_controlvendedoresform.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include "database.h"
#include "databasefunctions.h"

// Inicialización de los datos con valores por defecto
ControlVendedoresForm::ControlVendedoresForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlVendedoresForm)
{
    ui->setupUi(this);
    configurarTabla();
}

ControlVendedoresForm::~ControlVendedoresForm()
{
    delete ui;
}

// Configura las vistas de las tablas
void ControlVendedoresForm::configurarTabla()
{
    modeloVendedor = DataBase::newtablemodel(modeloVendedor,this);

    ui->tableViewVendedor->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewVendedor->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewVendedor->setModel(modeloVendedor);
}

void ControlVendedoresForm::on_pushButtonEliminarU_clicked()
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("DELETE FROM vendedor WHERE id ==  '%1' ").arg(filaID);

    db->doQuery(query);

    delete modeloVendedor;
    configurarTabla();
}

// Da los privilegios del usuario (si es que no los tiene)
void ControlVendedoresForm::givePrivilegios(int fila)
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("UPDATE vendedor set isAdmin='%1'  WHERE id='%2'")
            .arg("Administrador")
            .arg(fila);

    db->doQuery(query);
}

// Quita los privilegios del usuario (si es que los tiene)
void ControlVendedoresForm::removePrivilegios(int fila)
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("UPDATE vendedor set isAdmin='%1'  WHERE id='%2'")
            .arg("No Administrador")
            .arg(fila);

    db->doQuery(query);
}

// Cambia los privilegios de acuerdo a su condición actual
void ControlVendedoresForm::on_pushButtonCambiarPrivilegios_clicked()
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("SELECT isAdmin FROM vendedor WHERE id='%1'")
            .arg(filaID);

    auto q = db->doQuery(query);
    q.first();

    QString esAdmin;
    esAdmin = q.value(0).toString();

    void (*cambiar)(int);

    (esAdmin == "Administrador")?(cambiar = removePrivilegios):(cambiar = givePrivilegios);

    cambiar(filaID);

    delete modeloVendedor;
    configurarTabla();
}

void ControlVendedoresForm::on_tableViewVendedor_clicked(const QModelIndex &index)
{
    filaID = modeloVendedor->data(index).toInt();
}

int ControlVendedoresForm::getFilaID()
{
    return filaID;
}

