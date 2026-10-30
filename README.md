# Qt + C++ Learning Workspace

An experimental workspace for learning Qt 6 with modern C++ by building small,
focused modules that lead up to a full-stack desktop app (REST API + database + UI).

## Roadmap

Each module is a standalone executable under `modules/`. They all build from the
root `CMakeLists.txt`.

| #  | Module               | Key Qt concepts                                              | Status |
|----|----------------------|--------------------------------------------------------------|--------|
| 01 | hello-widgets        | `QApplication`, widgets, layouts, parent/child ownership, CMake | ✅ (runs) |
| 02 | signals-slots        | `QObject`, `Q_OBJECT`, moc, custom signals/slots, properties | 🚧 |
| 03 | core-types           | `QString`, containers, `QVariant`, `QDebug`, `QTimer`, event loop | ⏳ |
| 04 | model-view           | `QAbstractListModel`, `QTableView`, delegates, roles         | ⏳ |
| 05 | files-json-settings  | `QFile`, `QDir`, `QJsonDocument`, `QSettings`                | ⏳ |
| 06 | networking           | `QNetworkAccessManager`, REST calls, JSON parsing, errors    | ⏳ |
| 07 | database             | Qt SQL, SQLite, `QSqlQuery`, `QSqlTableModel`, migrations    | ⏳ |
| 08 | threading            | `QThread`, worker objects, `QtConcurrent`, `QFuture`         | ⏳ |
| 09 | qml-basics           | Qt Quick / QML, exposing C++ types and models to QML         | ⏳ |
| 10 | testing              | Qt Test, data-driven tests, `QSignalSpy`                     | ⏳ |
| ★  | capstone             | Full-stack app: QML UI + REST API sync + SQLite offline cache | ⏳ |

Widgets come first because they show Qt's core ideas (object tree, signals,
event loop) with the fewest moving parts. QML comes later for the capstone UI.

## Setup (Windows)

1. Install Qt with the **Qt Online Installer** (https://www.qt.io/download-qt-installer).
   It needs a free Qt account. Select:
   - **Qt 6.8 LTS** (or newer) → **MinGW 64-bit**
   - **Developer and Designer Tools** → **Qt Creator**, **CMake**, **Ninja**,
     **MinGW 64-bit** (the compiler matching the Qt build)
2. Open this folder's `CMakeLists.txt` in **Qt Creator** and pick the
   *Desktop Qt 6.x MinGW 64-bit* kit.
3. Choose a module target (e.g. `m01_hello_widgets`) in the run selector and press Run.

### Command-line build (optional)

From a terminal that has Qt's MinGW and CMake on `PATH`. The *Qt 6.x (MinGW)*
shortcut in the Start menu opens one. Then run:

```sh
cmake -S . -B build -G Ninja -DCMAKE_PREFIX_PATH=C:/Qt/6.8.3/mingw_64
cmake --build build
./build/modules/01-hello-widgets/m01_hello_widgets.exe
```

Change the version in `CMAKE_PREFIX_PATH` to match your install.
