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
#include <QStringListModel>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots: 
    void onDSCliked(const QModelIndex &index);
    void onOpenStructure();

private: 
    Ui::MainWindow ui; // oggetto UI generato
    QStringListModel *modelListData;      // modello per la lista
    QString selectedStructure;

    

};

#endif // MAINWINDOW_H
