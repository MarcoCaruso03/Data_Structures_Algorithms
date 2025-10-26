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
    ui.setupUi(this);  // collega tutti i widget dal .ui

    connect(ui.addButton, &QPushButton::clicked, this, &MainWindow::aggiungiDato);

    listaDati << "Dato 1" << "Dato 2";
    aggiornaGUI();
}


void MainWindow::aggiungiDato() {
    QString testo = ui.inputLine->text();
    if (!testo.isEmpty()) {
        listaDati.append(testo);
        ui.inputLine->clear();
        aggiornaGUI();
    }
}

void MainWindow::aggiornaGUI() {
    ui.outputText->clear();
    for (const QString &dato : listaDati)
        ui.outputText->append(dato);
}
