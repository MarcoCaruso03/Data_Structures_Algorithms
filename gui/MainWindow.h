#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStringList>
#include "ui_mainwindow.h" // generato da Qt Designer

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots: 
    void aggiungiDato();     // aggiunge un nuovo dato
    void aggiornaGUI();      // aggiorna il QTextEdit


private: 
    Ui::MainWindow ui;  // oggetto generato da Qt Designer
    QStringList listaDati;

};

#endif // MAINWINDOW_H
