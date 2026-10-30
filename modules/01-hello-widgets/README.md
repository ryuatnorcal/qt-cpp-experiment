# 01 — Hello Widgets

A window with a text field, a button and a label. Typing a name and pressing
**Greet** (or Enter) updates the label.

## What to learn here

- **`QApplication`**: the single application object. `app.exec()` starts the
  *event loop*, which waits for clicks and keypresses and dispatches them.
- **Widgets**: `QWidget` is the base of every visual element. A widget with no
  parent is a top-level window.
- **Layouts**: `QVBoxLayout` stacks children vertically and resizes them along
  with the window. In Qt you rarely position widgets by hand with pixel coordinates.
- **Parent/child ownership**: the most important memory rule in Qt.
  When a `QObject` is deleted, it deletes all of its children. That's why we
  `new` widgets and never `delete` them: the window owns them.
- **`connect()`**: a first look at signals and slots. Module 02 goes deeper.
- **CMake + Qt**: `find_package(Qt6 ...)`, `qt_add_executable`,
  `target_link_libraries(... Qt6::Widgets)`.

## Exercises

1. Add a **Clear** button that empties the text field and resets the label.
2. Disable the Greet button while the text field is empty.
   Hint: `QLineEdit::textChanged` and `QWidget::setEnabled`.
3. Replace the `QVBoxLayout` with a `QFormLayout` that has the label "Name:"
   next to the field.
4. Make the label text bold and larger using `setStyleSheet(...)`.
