#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <QString>

// Almacena los datos de un objeto administrador
class Administrador
{
    int idAdmin;
    QString nombreAdmin;
    QString claveAdmin;
    QString privilegios;

public:
    //Constructor
    Administrador(int id = -1, const QString &nombre = "", const QString &clave = "");

    //Métodos getters
    int getId() const {return idAdmin;}
    QString getNombre() const {return nombreAdmin;}
    QString getClave() const {return claveAdmin;}
    QString getPrivilegios() const {return privilegios;}

    //Métodos setters
    void setId(int newId) {idAdmin = newId;}
    void setNombre(QString &newNombre) {nombreAdmin= newNombre;}
    void setClave(QString &newClave) {claveAdmin = newClave;}

    //Sobrecarga del operador de Asignación
    void  operator= (Administrador newAdministrador);
};

#endif // ADMINISTRADOR_H
