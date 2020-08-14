#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H


#include "producto.h"
#include <QSqlQuery>
#include <thread>


//Clase functor
class DataBaseFunctions
{
public:
    DataBaseFunctions();

    //Sobrecarag del operadores
    Producto operator()(int index);
    void operator()(Producto p1, int index);
    void operator++ (int n);

    //Método que obtiene el nombre del thread
    static QString getThreadId(QString conexion, std::thread::id id);




private:
    int cantidadDeVentas = 0;
};

#endif // DATABASEFUNCTIONS_H



