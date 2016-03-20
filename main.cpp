#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>
#include <QDebug>
#include "mydbusadaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (!QDBusConnection::systemBus().isConnected()) {
        qDebug() << "Cannot connect to the D-Bus session bus";
        qDebug() << QDBusConnection::systemBus().lastError().message();
        return 1;
    }

    if (!QDBusConnection::systemBus().registerService("org.test.my")) {
        qDebug() << QDBusConnection::systemBus().lastError().message();
        return 1;
    }

    new MyDBusAdaptor(&a);
    QDBusConnection::systemBus().registerObject("/", &a);

    return a.exec();
}
