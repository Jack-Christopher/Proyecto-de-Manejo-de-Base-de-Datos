#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QString>

// Almacena los datos de un objeto Producto
class Producto
{
    int idProducto;
    QString nombreProducto;
    QString marcaProducto;
    double precioProducto;
    int cantidadProducto;
public:
    //Constructor
    Producto(int id = -1, const QString &nombre = "", const QString &marca = "", const double precio = 0, const int cantidad = 0);

    //Métodos getters
    int getIdP() const {return idProducto;}
    QString getNombreP() const {return nombreProducto;}
    QString getMarcaP() const {return marcaProducto;}
    double getPrecio() const {return precioProducto;}
    int getCantidad() const {return  cantidadProducto;}

    //Métodos setters
    void setIdP(int newId) {idProducto = newId;}
    void setNombreP(QString &newNombre) {nombreProducto = newNombre;}
    void setMarcaP(QString &newMarca) {marcaProducto = newMarca;}
    void setPrecioP(double newPrecio) {precioProducto = newPrecio;}
    void setCantidadP(int newCantidad) {cantidadProducto = newCantidad;}

    //Sobrecarga de operadores
    void  operator= (Producto newProducto);

    void operator-- (int n);
};

#endif // PRODUCTO_H
