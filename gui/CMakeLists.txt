set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(DSAGui
    main.cpp
    MainWindow.cpp
    mainwindow.ui
)

target_link_libraries(DSAGui Qt5::Widgets)
