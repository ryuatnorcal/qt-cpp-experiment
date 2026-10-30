find_package(Qt6 REQUIRED COMPONENTS Widgets)

# List the headers too: AUTOMOC (enabled by qt_standard_project_setup)
# scans them for Q_OBJECT and runs moc on them.
qt_add_executable(m02_signals_slots
    main.cpp
    counter.h counter.cpp
    counterwindow.h counterwindow.cpp
)

target_link_libraries(m02_signals_slots PRIVATE Qt6::Widgets)

# No WIN32_EXECUTABLE here, so this builds as a console app and qDebug()
# output also shows up when you run it from a terminal.
