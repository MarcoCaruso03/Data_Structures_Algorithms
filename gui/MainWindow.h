#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStringList>
#include <QStackedWidget>
#include "ui_mainwindow.h"  

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots: 
    


private: 
    Ui::MainWindow ui; // oggetto UI generato

};

#endif // MAINWINDOW_H
