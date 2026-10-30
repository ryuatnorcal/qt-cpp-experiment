# 02 — Signals & Slots

A counter from 0 to 10 that you can change with a **+1** button, a **Reset**
button, or a slider. All three stay in sync. The state lives in a separate
`Counter` object, not in the widgets.

## Files

| File | Role |
|---|---|
| `counter.h/.cpp` | A `QObject` "model" with its own signals, slots and `Q_PROPERTY` |
| `counterwindow.h/.cpp` | A `QWidget` subclass that builds the UI and wires the connections |
| `main.cpp` | Starts the app, plus a meta-object demo printed to Application Output |

## What to learn here

- **`Q_OBJECT` and moc**: the macro tells the build to run moc, which
  generates the code behind signals, properties and `metaObject()`. Any class
  that declares signals needs it, and it must derive from `QObject`.
- **Declaring signals**: you declare them in `signals:` and never implement
  them. Fire one with `emit`.
- **Slots**: normal member functions. Any member function or lambda can be
  connected to a signal.
- **`connect(sender, &Sender::signal, receiver, &Receiver::slot)`**: the
  compiler checks the signal and slot types, so a mismatch fails to build.
  A slot may take *fewer* arguments than the signal provides.
- **One signal → many slots**: `valueChanged` updates the slider *and* the label.
- **Two-way sync without infinite loops**: slider → counter → slider is
  safe only because `setValue` returns early when the value didn't change.
  Always guard your setters this way.
- **Separating model from UI**: `Counter` has no idea widgets exist. That's
  why it can be reused from tests, a network handler, or QML later.
- **`Q_PROPERTY`**: lets you read and write a value by name at runtime. QML
  relies on this heavily (module 09).

## Exercises

1. **Signal → signal.** Add a `doubleClickedReset()` signal to `CounterWindow`
   and connect it straight to `Counter::reset`. No slot in between, since a
   signal can be the target of `connect`. Emit it from `mouseDoubleClickEvent`.
2. **Disconnect.** `connect()` returns a `QMetaObject::Connection`. Store the
   slider → counter connection and add a "Lock slider" checkbox that
   disconnects and reconnects it.
3. **New signal with an argument.** Add `stepped(int oldValue, int newValue)`
   to `Counter`, and show "3 → 4" in the status label.
4. **Make the maximum a property.** Add `Q_PROPERTY(int maximum ... NOTIFY
   maximumChanged)` with a setter, plus a `QSpinBox` that changes it. The
   slider range must follow.
5. **Break it on purpose.** Remove `Q_OBJECT` from `counter.h` and rebuild.
   Read the error, then put it back.
