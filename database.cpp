#include "database.h"
#include <QString>
#include <QSqlQuery>
#include <thread>
#include <QDebug>
#include <QSqlError>
#include "databasefunctions.h"
#include "controlproductosform.h"
#include "controlvendedoresform.h"

// Crea una base de datos si no ha sido creada todavía
// de lo contrario devuelve la base de datos creada
DataBase::DataBase(QString nombreDeConexion)
{
    singletonDatabase = QSqlDatabase::addDatabase("QSQLITE", nombreDeConexion);
    if(singletonDatabase.databaseName() != "./data.db")
    {
        singletonDatabase.setDatabaseName("./data.db");
    }
}

// Se hace uso del Patrón de Diseño Lazy Initialization, se
// inicializa con valores vaíos o nulos al inicio solo se
// les otorga los valore reales cuando se vayan a usar
DataBase *DataBase::dataBaseInstance{nullptr};
QSqlDatabase DataBase::singletonDatabase{};
std::mutex DataBase::myMutex;

//Devuelve la instancia a la base de datos única
DataBase *DataBase::getInstance(QString nombreDeConexion)
{
    if (dataBaseInstance == nullptr)
    {
        std::lock_guard<std::mutex> lock(myMutex);
        if (dataBaseInstance == nullptr)
        {
            dataBaseInstance = new DataBase(nombreDeConexion);
        }
    }

    return dataBaseInstance;
}

// Crea las tablas necesarias
int DataBase::doQuery(QString usuario, QString clave)
{
    const QString DRIVER = "QSQLITE";

    //DataBase *db= DataBase::getInstance(nombreDeConexion);

    if (!QSqlDatabase::isDriverAvailable(DRIVER))
    {
        qDebug() << "Driver no existe";
        return -1;
    }
    else
    {

        if (!singletonDatabase.open())
        {
            qDebug() << singletonDatabase.lastError().text();
            return -2;
        }

        QSqlQuery q(singletonDatabase);
        q.exec("CREATE TABLE IF NOT EXISTS vendedor(id INTEGER PRIMARY KEY NOT NULL,"
               "nombre TEXT NOT NULL UNIQUE, clave TEXT NOT NULL, isAdmin TEXT NOT NULL)");

        q.exec(QString("INSERT INTO vendedor (id, nombre, clave,isAdmin) VALUES (1,'%1', '%2', 'Administrador')")
               .arg(usuario)
               .arg(clave));

        q.exec("CREATE TABLE IF NOT EXISTS producto(id INTEGER PRIMARY KEY NOT NULL,"
               "nombre TEXT NOT NULL, marca TEXT NOT NULL , precio DOUBLE NOT NULL, cantidad INT NOT NULL)");
    }

    return 0;
}

// Almacena los usuarios en un vector de tuplas
void DataBase::doQuery(QVector<std::tuple<QString,QString,QString>> &secuenciaDeUsuarios)
{
    QSqlQuery q(singletonDatabase);

    singletonDatabase.open();

    q.exec("SELECT nombre, clave, isAdmin FROM vendedor");

    while (q.next())
    {
        QString nombre = q.value(0).toString();
        QString clave = q.value(1).toString();
        QString isAdmin = q.value(2).toString();
        std::tuple<QString,QString,QString> Usuario(nombre, clave, isAdmin);

        secuenciaDeUsuarios.append(Usuario);
    }

}

// Ejecuta una consulta a la base de datos
QSqlQuery DataBase::doQuery(QString query)
{
    QSqlQuery q(singletonDatabase);
    q.exec(query);
    return q;
}

//Configura las tablas de los datos (Productos o Vendedores)

QSqlTableModel *DataBase::newtablemodel(QSqlTableModel * modelo, ControlProductosForm * ptr)
{
    modelo = new QSqlTableModel(ptr, singletonDatabase);
    modelo->setTable("producto");
    modelo->select();
    modelo->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    modelo->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre"));
    modelo->setHeaderData(2, Qt::Horizontal, QObject::tr("Marca"));
    modelo->setHeaderData(3, Qt::Horizontal, QObject::tr("Precio"));
    modelo->setHeaderData(4, Qt::Horizontal, QObject::tr("Cantidad"));

    return modelo;
}


QSqlTableModel *DataBase::newtablemodel(QSqlTableModel * modelo, ControlVendedoresForm * ptr)
{
    modelo = new QSqlTableModel(ptr, singletonDatabase);
    modelo->setTable("vendedor");
    modelo->select();
    modelo->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    modelo->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre"));
    modelo->setHeaderData(2, Qt::Horizontal, QObject::tr("Clave"));
    modelo->setHeaderData(3, Qt::Horizontal, QObject::tr("Privilegios"));
    return modelo;
}
