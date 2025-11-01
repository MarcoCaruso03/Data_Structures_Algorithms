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

    QStringList structures;
    structures << "Dynamic Array"
               << "Linked List"
               << "Stack"
               << "Queue"; 

    modelListData = new QStringListModel(this);
    modelListData->setStringList(structures);
    ui.listDataStructure->setModel(modelListData);
    

    // Connect the Start button to change the page
    connect(ui.btnStart, &QPushButton::clicked, this, [this]() {
        ui.stack->setCurrentIndex(1);
    });
    connect(ui.listDataStructure, &QListView::clicked, this, &MainWindow::onDSCliked);
    connect(ui.btnOpenStruct, &QPushButton::clicked, this, &MainWindow::onOpenStructure);



    
    ui.stack->setCurrentIndex(0); // welcome page
    ui.stackPreview->setCurrentWidget(ui.tutorialPage);
}


void MainWindow::onDSCliked(const QModelIndex &index){
    selectedStructure = modelListData->data(index, Qt::DisplayRole).toString();
    std::cout << "Data structure selezionata: "
          << selectedStructure.toStdString() << std::endl;
    // set the preview page
    if (selectedStructure == "Dynamic Array")
        ui.stackPreview->setCurrentWidget(ui.arrayPagePrev);
    else if (selectedStructure == "Linked List")
        ui.stackPreview->setCurrentWidget(ui.LinkedListPagePrev);
    else if (selectedStructure == "Stack")
        ui.stackPreview->setCurrentWidget(ui.StackPagePrev);
    else if (selectedStructure == "Queue")
        ui.stackPreview->setCurrentWidget(ui.QueuePagePrev);
    else
        ui.stackPreview->setCurrentWidget(ui.tutorialPage);

}
void MainWindow::onOpenStructure() {

}
