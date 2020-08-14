#ifndef FACADE_H
#define FACADE_H


#include <thread>
#include <QApplication>


// Se hace uso del patrón de Diseño  State
// para poder ejecutarse el programa de acuerdo
// al estado en el que se encuentra
enum state { esperando, cerrarSesion, cerrarAplicacion};


// Se hace uso del patrón de Diseño Facade para
// simplificar el uso de las funciones
class Facade
{
    state theState;
public:
    Facade();

    //Ejecuta la aplicación
    int ejecutarAplicacion(std::shared_ptr<QApplication> aplicacion);

    // Inicia un thread para ejecutar el método crea_configuraBaseDatos()
    void ejecutarConfiguracion();

    // Crea y configura la Base de Datos
    int crea_configuraBaseDatos(QString usuario, QString clave);

    // Devuelve un smart pointer que apunta a la aplicación que
    // se ejecutarpa
    std::shared_ptr<QApplication> getSmartPointer(int argc, char *argv[]);

    // Cambia el estado de la aplicación
    void changeState(int st);



};

#endif // FACADE_H
