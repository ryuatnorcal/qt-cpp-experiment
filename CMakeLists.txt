cmake_minimum_required(VERSION 3.21)
project(QtLearning VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Each module calls find_package() for the Qt components it needs.
find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

# Turns on AUTOMOC/AUTOUIC/AUTORCC and sensible defaults (Qt >= 6.3).
qt_standard_project_setup()

add_subdirectory(modules/01-hello-widgets)
add_subdirectory(modules/02-signals-slots)
