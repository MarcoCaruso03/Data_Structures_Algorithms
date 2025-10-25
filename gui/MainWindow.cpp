#include "MainWindow.h"
#include <QVBoxLayout>
#include <QString>
#include <iostream>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Widget principali
    button = new QPushButton("Invia", this);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    input = new QLineEdit(this);

    // Layout 
    QHBoxLayout * topLayout = new QHBoxLayout();
    topLayout->addWidget(input);
    topLayout->addWidget(button);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(textEdit);

    QWidget * central = new QWidget(this);
    central->setLayout(mainLayout);
    setCentralWidget(central);

    // Azioni
    newAction = new QAction("Nuovo", this);
    exitAction = new QAction("Esci", this);
    aboutAction = new QAction("About", this);
    redAction = new QAction("Colora rosso", this);
    blueAction = new QAction("Colora blu", this);


    // Shortcut
    newAction->setShortcut(QKeySequence::New);
    exitAction->setShortcut(QKeySequence::Quit);

    // collegamenti
    connect(button, &QPushButton::clicked, this, &MainWindow::addText);
    connect(input, &QLineEdit::returnPressed, this, &MainWindow::addText);
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApp);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    connect(redAction, &QAction::triggered, this, &MainWindow::setRedText);
    connect(blueAction, &QAction::triggered, this, &MainWindow::setBlueText);

    // Menu
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(newAction);
    fileMenu->addAction(exitAction);

    QMenu *optionsMenu = menuBar()->addMenu("Opzioni");
    optionsMenu->addAction(redAction);
    optionsMenu->addAction(blueAction);
     
    QMenu *helpMenu = menuBar()->addMenu("Help");
    helpMenu->addAction(aboutAction);

    // Tool Bar
    QToolBar *toolbar = addToolBar("Main Toolbar");
    toolbar->addAction(newAction);
    toolbar->addAction(aboutAction);
}
// slots
void MainWindow::addText(){
    QString text = input->text();
    if(!text.isEmpty()) {
        textEdit->append(text);
        input->clear();
    }
}
void MainWindow::newFile()
{
    textEdit->clear();
}
void MainWindow::exitApp()
{
    close();
}
void MainWindow::showAbout()
{
    QMessageBox::information(this, "About", "Questa è un'applicazione di test Qt (recap Capitoli 1-5)!");
}
void MainWindow::setRedText()
{
    textEdit->setTextColor(Qt::red);
}
void MainWindow::setBlueText()
{
    textEdit->setTextColor(Qt::blue);
}