#pragma once

#include <QWidget>

class Counter;
class QLabel;
class QPushButton;
class QSlider;
class QCheckBox;

// In module 01 we built the UI inside main(). Real apps subclass QWidget
// so the window owns its children and its own logic.
class CounterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CounterWindow(QWidget *parent = nullptr);

private slots:
    void onValueChanged(int value);

private:
    // Raw pointers are fine here: every one of these gets `this` (or a layout
    // on `this`) as parent, so Qt deletes them when the window is destroyed.
    // Members are initialized in this order, so keep it in sync with the
    // constructor's initializer list.
    Counter *m_counter;
    QLabel *m_valueLabel;
    QSlider *m_slider;
    QPushButton *m_incrementButton;
    QPushButton *m_resetButton;
    QLabel *m_statusLabel;
    QCheckBox *m_lockCheckBox;
    QMetaObject::Connection m_sliderConnection;

};
