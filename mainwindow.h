#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include "connexion.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    connexion* mClient;


protected:

    void paintEvent(QPaintEvent *);

private slots:
    void clientConnected();
    void clientNotConnected();
    void connexionClient();
    void clientSendMess();
};

#endif // MAINWINDOW_H
