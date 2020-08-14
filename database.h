#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <mutex>
#include <QSqlTableModel>
#include "controlproductosform.h"
#include "controlvendedoresform.h"

// Clase que sigue el patrón  de Diseño "Singleton"
// Para que en el transurso de la ejecución de todo el programa
// se trabaje con la misma base de datos
class DataBase
{
    // Elementos del Singleton
    static DataBase *dataBaseInstance;
    static QSqlDatabase singletonDatabase;
    // Necesario para que la clase sea Thread-Safe
    static std::mutex myMutex;

    QString nombreDeConexion;

    DataBase(QString nombre);
    ~DataBase() {}

public:

    // Método que devueleve la instancia de la base de datos
    static DataBase *getInstance(QString nombreDeConexion);

    // Se eliminan explicitamente los constructores y operador de asignación por defecto
    DataBase(DataBase &other) = delete;
    void operator=(const DataBase &) = delete;

    // Sobrecarga de funciones
    QSqlQuery doQuery(QString query);
    int doQuery(QString usuario, QString clave);
    void doQuery(QVector<std::tuple<QString,QString,QString>> &secuenciaDeUsuarios);

    //Métodos que crean nuevas vistas de la tablas de la base de datos
    static QSqlTableModel *newtablemodel(QSqlTableModel * modelo, ControlProductosForm * ptr);
    static QSqlTableModel *newtablemodel(QSqlTableModel * modelo, ControlVendedoresForm * ptr);
};

#endif // DATABASE_H
