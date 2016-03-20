#include "mydbusadaptor.h"

#include <QTimer>
#include <QDebug>

MyDBusAdaptor::MyDBusAdaptor(QObject *parent):
    QDBusAbstractAdaptor(parent),
    timer(new QTimer(this))
{
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);
}

QString MyDBusAdaptor::doSomething(int first, double second)
{
    qDebug() << "doing something...";
    return QString::number(first * second);
}

void MyDBusAdaptor::onTimeout()
{
    static int i = 0;
    i ++;
    emit somethingHappened(QString::number(i));
}
