#pragma once

#include <QObject>

// A plain "model" object with no UI. It only knows about its value and
// announces changes through signals. Anything can listen: a widget, a
// logger, a test, or QML later on.
class Counter : public QObject
{
    // Q_OBJECT is required for signals, slots and properties. It makes moc
    // (the Meta-Object Compiler) generate extra C++ code for this class at
    // build time. If you forget it, connect() to your signals fails to compile.
    Q_OBJECT

    // Q_PROPERTY exposes `value` to Qt's meta-object system, so it can be read
    // and written by name at runtime (setProperty("value", 3)), and later bound
    // from QML. NOTIFY names the signal emitted when it changes.
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit Counter(int maximum, QObject *parent = nullptr);

    int value() const;
    int maximum() const;

public slots:
    // Slots are ordinary member functions that can also be connection targets.
    // (In Qt 5/6, any member function or lambda can be connected to a signal;
    // `slots` mainly documents intent and makes them callable by name.)
    void setValue(int value);
    void increment();
    void reset();

signals:
    // Signals are declared but never implemented: moc writes the bodies.
    // You fire one with `emit valueChanged(42);`.
    void valueChanged(int newValue);
    void maximumReached();

private:
    int m_value = 0;
    int m_maximum;
};
