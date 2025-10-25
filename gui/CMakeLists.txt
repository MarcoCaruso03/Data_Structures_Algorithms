find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)  # 🔹 abilita la generazione automatica dei moc files

add_executable(DSAGui
    main.cpp
    MainWindow.cpp
)

target_include_directories(DSAGui PUBLIC ../include)
target_link_libraries(DSAGui Qt5::Widgets)
