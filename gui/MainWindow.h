#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots: 
    void addText();       // inserisce testo da QLineEdit a QTextEdit
    void newFile();       // pulisce QTextEdit
    void exitApp();       // chiude app
    void showAbout();     // QMessageBox informativo
    void setRedText();    // cambia colore testo in rosso
    void setBlueText();   // cambia colore testo in blu



private: 
    QTextEdit * textEdit; 
    QPushButton * button; 
    QLineEdit * input; 
    QAction *newAction;
    QAction *exitAction;
    QAction *aboutAction;
    QAction *redAction;
    QAction *blueAction;

};

#endif // MAINWINDOW_H
