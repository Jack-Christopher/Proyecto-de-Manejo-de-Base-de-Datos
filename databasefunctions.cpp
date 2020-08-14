#include <QSqlQuery>
#include <QString>
#include <thread>
#include <sstream>
#include "producto.h"
#include "database.h"
#include "databasefunctions.h"

DataBaseFunctions::DataBaseFunctions()
{

}


// Obtiene un producto de la base de datos
// usando e índice de éste
Producto DataBaseFunctions::operator()(int index)
{
    Producto p1;

    // Controla el numero de vetas posibles
    if (cantidadDeVentas > 14)
    {
        return p1;
    }

    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString( "SELECT nombre, marca, precio, cantidad FROM producto WHERE id == '%1' ").arg(index);

    QSqlQuery q = db->doQuery(query);
    q.next();

    QString nombre = q.value(0).toString();
    QString marca = q.value(1).toString();
    double precio = q.value(2).toString().toDouble();
    int cantidad= q.value(3).toString().toInt();


    p1.setMarcaP(marca);
    p1.setNombreP(nombre);
    p1.setPrecioP(precio);
    p1.setCantidadP(cantidad);

    return p1;
}

// Actualiza los datos de un producto
void DataBaseFunctions::operator()(Producto p1, int index)
{
    QString nombreDeConexion =  DataBaseFunctions::getThreadId("Conexion_", std::this_thread::get_id());

    DataBase *db = DataBase::getInstance(nombreDeConexion);

    QString query = QString("UPDATE producto SET nombre = '%1', marca = '%2', precio = '%3', cantidad = '%4' WHERE id = '%5'")
             .arg(p1.getNombreP())
             .arg(p1.getMarcaP())
             .arg(p1.getPrecio())
             .arg(p1.getCantidad())
             .arg(index);

    db->doQuery(query);
}

// Devuelve el nombre del thread actual
QString DataBaseFunctions::getThreadId(QString conexion, std::thread::id id)
{
    QString nombreDeConexion = conexion;
    auto threadId = id;

    std::ostringstream ss;
    ss << threadId;
    std::string sId = ss.str();

    nombreDeConexion += QString::fromStdString( sId);

    return nombreDeConexion;
}

// Sobrecarga de operador de postincremento
void DataBaseFunctions::operator++ (int n)
{
    cantidadDeVentas++;
}
