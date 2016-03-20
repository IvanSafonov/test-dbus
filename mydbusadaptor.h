#ifndef MYDBUSADAPTOR_H
#define MYDBUSADAPTOR_H

#include <QtDBus/QDBusAbstractAdaptor>

class QTimer;

class MyDBusAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.test.my.Adaptor")
public:
    MyDBusAdaptor(QObject *parent);

public slots:
    QString doSomething(int first, double second);

signals:
    void somethingHappened(QString msg);

private slots:
    void onTimeout();

private:
    QTimer *timer;

};

#endif // MYDBUSADAPTOR_H
