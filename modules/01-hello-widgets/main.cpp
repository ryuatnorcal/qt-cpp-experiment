#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    // 1. Exactly one QApplication per GUI program. It owns the event loop.
    QApplication app(argc, argv);

    // 2. A top-level widget with no parent becomes a window.
    //    It lives on the stack, so it is destroyed when main() returns.
    QWidget window;
    window.setWindowTitle("01 - Hello Widgets");

    // 3. Passing &window makes the layout manage the window's children.
    auto *layout = new QVBoxLayout(&window);

    // 4. These are created without a parent, but addWidget() reparents them
    //    to `window`. Qt then deletes them automatically along with `window`,
    //    which is why there is no matching `delete` anywhere.
    auto *nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Type your name...");
    auto *greetButton = new QPushButton("Greet");
    auto *output = new QLabel("Hello, Qt!");

    layout->addWidget(nameEdit);
    layout->addWidget(greetButton);
    layout->addWidget(output);

    // 5. Signals & slots: when the button emits clicked(), run this lambda.
    //    The third argument (`output`) is the "context" object: if it is
    //    destroyed, the connection is removed automatically.
    QObject::connect(greetButton, &QPushButton::clicked, output, [nameEdit, output] {
        const QString name = nameEdit->text().trimmed();
        if (name.isEmpty())
            output->setText("Hello, stranger!");
        else
            output->setText(QString("Hello, %1!").arg(name));
    });

    // Signal-to-slot without a lambda: pressing Enter "clicks" the button.
    QObject::connect(nameEdit, &QLineEdit::returnPressed, greetButton, &QPushButton::click);

    window.resize(320, 140);
    window.show();

    // 6. Hand control to Qt. exec() returns when the last window closes.
    return app.exec();
}
