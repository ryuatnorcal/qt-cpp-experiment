#include "counterwindow.h"

#include "counter.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QCheckBox>

CounterWindow::CounterWindow(QWidget *parent)
    : QWidget(parent)
    , m_counter(new Counter(10, this)) // not a widget, but `this` still owns it
    , m_valueLabel(new QLabel)
    , m_slider(new QSlider(Qt::Horizontal))
    , m_incrementButton(new QPushButton("+1"))
    , m_resetButton(new QPushButton("Reset"))
    , m_statusLabel(new QLabel)
    , m_lockCheckBox(new QCheckBox("Lock Slider"))
{
    setWindowTitle("02 - Signals & Slots");

    QFont bigFont = m_valueLabel->font();
    bigFont.setPointSize(28);
    bigFont.setBold(true);
    m_valueLabel->setFont(bigFont);
    m_valueLabel->setAlignment(Qt::AlignCenter);

    m_slider->setRange(0, m_counter->maximum());
    m_sliderConnection = connect(m_slider, &QSlider::valueChanged, m_counter, &Counter::setValue);

    // Layouts can be nested: a horizontal row of buttons inside a vertical stack.
    auto *buttonRow = new QHBoxLayout;
    buttonRow->addWidget(m_incrementButton);
    buttonRow->addWidget(m_resetButton);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_valueLabel);
    layout->addWidget(m_slider);
    layout->addWidget(m_lockCheckBox);
    layout->addLayout(buttonRow);
    layout->addWidget(m_statusLabel);

    // --- UI -> model -------------------------------------------------------
    // Signal to slot on another object. clicked(bool) has an argument that
    // increment() doesn't take. That's allowed: extra arguments are dropped.
    connect(m_incrementButton, &QPushButton::clicked, m_counter, &Counter::increment);
    connect(m_resetButton, &QPushButton::clicked, m_counter, &Counter::reset);
    // connect(m_slider, &QSlider::valueChanged, m_counter, &Counter::setValue);

    // --- model -> UI -------------------------------------------------------
    // One signal can drive many slots. They run in the order they were connected.
    // connect(m_counter, &Counter::valueChanged, m_slider, &QSlider::setValue);
    connect(m_counter, &Counter::valueChanged, this, &CounterWindow::onValueChanged);
    connect(m_lockCheckBox, &QCheckBox::toggled, this, [this](bool checked) {
        if (checked) {
            // locked: cut the slider -> counter wire
            // disconnect(m_sliderConnection);
            m_slider->setEnabled(!checked);
        } else {
            // unlocked: wire it back up and keep the new handle
            m_slider->setEnabled(checked);
            m_sliderConnection = connect(m_slider, &QSlider::valueChanged,
                                         m_counter, &Counter::setValue);
        }
    });

    // A lambda works as a slot too. `this` is the context object, so the
    // connection is removed automatically if the window dies first.
    connect(m_counter, &Counter::maximumReached, this, [this] {
        m_statusLabel->setText("Maximum reached!");
    });

    // Signals only fire on *changes*, so sync the initial state by hand.
    onValueChanged(m_counter->value());
}

void CounterWindow::onValueChanged(int value)
{
    m_valueLabel->setText(QString::number(value));
    m_incrementButton->setEnabled(value < m_counter->maximum());
    m_statusLabel->clear(); // maximumReached is emitted after this, so it wins
}
