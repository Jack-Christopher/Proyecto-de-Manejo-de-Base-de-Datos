#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "administrador.h"

#include <QString>
#include <QDebug>

// Almacena los datos de un objeto Producto
class Vendedor : public Administrador
{
    int idVendedor;
    QString nombreVendedor;
    QString claveVendedor;
    QString privilegios;

public:
    //Constructor
    Vendedor(int id = -1, const QString &nombre = "", const QString &clave = "");

    //Métodos getters
    int getId() const {return idVendedor;}
    QString getNombre() const {return nombreVendedor;};
    QString getClave() const {return claveVendedor;};
    QString getPrivilegios() const {return privilegios;}

    //Métodos setters
    void setId(int newId) {idVendedor = newId;}
    void setNombre(QString &newNombre) {nombreVendedor= newNombre;}
    void setClave(QString &newClave) {claveVendedor = newClave;}
    void setPrivilegios(QString &newstatus) {privilegios = newstatus;}

    void  operator= (Vendedor newVendedor);

    friend bool operator<( Vendedor newVendedor, Vendedor oldVendedor);

};

#endif // VENDEDOR_H



