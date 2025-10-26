#include "MainWindow.h"
#include <QVBoxLayout>
#include <QString>
#include <iostream>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Setup the UI from Designer
    ui.setupUi(this);

    // Connect the Start button to change the page
    connect(ui.btnStart, &QPushButton::clicked, this, [this]() {
        ui.stack->setCurrentIndex(1);
    });

    // Optional: set initial page
    ui.stack->setCurrentIndex(0); // welcome page
}


