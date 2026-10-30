#include "counter.h"

#include <algorithm>

Counter::Counter(int maximum, QObject *parent)
    : QObject(parent) // pass the parent up so the object tree owns us
    , m_maximum(maximum)
{
}

int Counter::value() const
{
    return m_value;
}

int Counter::maximum() const
{
    return m_maximum;
}

void Counter::setValue(int value)
{
    value = std::clamp(value, 0, m_maximum);

    // Important pattern: only emit when something actually changed.
    // That stops infinite loops when two objects are connected both ways
    // (slider -> counter -> slider -> ...).
    if (value == m_value)
        return;

    m_value = value;
    emit valueChanged(m_value);

    if (m_value == m_maximum)
        emit maximumReached();
}

void Counter::increment()
{
    setValue(m_value + 1);
}

void Counter::reset()
{
    setValue(0);
}
