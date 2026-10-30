find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(m01_hello_widgets
    main.cpp
)

target_link_libraries(m01_hello_widgets PRIVATE Qt6::Widgets)

# On Windows, build as a GUI app (no console window).
# Remove this line if you want to see qDebug() output in a console.
set_target_properties(m01_hello_widgets PROPERTIES WIN32_EXECUTABLE ON)
