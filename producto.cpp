#include "producto.h"
#include <QString>

// Inicialización de los datos con valores por defecto
Producto::Producto(int id , const QString &nombre , const QString &marca, const double precio, const int cantidad)
    :idProducto(id)
    , nombreProducto(nombre)
    , marcaProducto(marca)
    , precioProducto(precio)
    , cantidadProducto(cantidad)


{

}

// Sobrecarga de operadores

void Producto::operator-- (int n)
{
    cantidadProducto --;
}

void Producto::operator= (Producto newProducto)
{
    idProducto = newProducto.getIdP();
    nombreProducto = newProducto.getNombreP();
    marcaProducto = newProducto.getMarcaP();
    precioProducto = newProducto.getPrecio();
    cantidadProducto = newProducto.getCantidad();
}
