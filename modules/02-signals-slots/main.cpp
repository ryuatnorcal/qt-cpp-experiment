#include "counter.h"
#include "counterwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMetaObject>

// Shows what Q_OBJECT + moc give you beyond signals: runtime introspection.
// The output appears in Qt Creator's "Application Output" pane.
static void demoMetaObject()
{
    Counter probe(5);

    // A connection with no context object, straight to a lambda.
    QObject::connect(&probe, &Counter::valueChanged, [](int v) {
        qDebug() << "probe emitted valueChanged:" << v;
    });

    // Set the property *by name*. This goes through the Q_PROPERTY WRITE
    // accessor (setValue), so the signal still fires. QML uses this same mechanism.
    probe.setProperty("value", 3);

    qDebug() << "class name:" << probe.metaObject()->className();
    qDebug() << "value read by name:" << probe.property("value").toInt();

    // Clamped to the maximum (5), then maximumReached is emitted.
    probe.setValue(99);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    demoMetaObject();

    CounterWindow window;
    window.resize(300, 200);
    window.show();

    return app.exec();
}
