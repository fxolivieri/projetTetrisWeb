#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pbEnvoyerPiece->setDisabled(true);

    mClient = NULL;

    QObject::connect(ui->pbConnexion,SIGNAL(clicked()),this,SLOT(connexionClient()));
    QObject::connect(ui->pbEnvoyerPiece,SIGNAL(clicked()),this,SLOT(clientSendMess()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connexionClient()
{
    if (mClient == NULL)
    {
        mClient = new connexion(ui->textAdresse->text(),ui->textPort->text().toInt());
        QObject::connect(mClient,SIGNAL(connected()),this,SLOT(clientConnected()));
        QObject::connect(mClient,SIGNAL(clientError()),this,SLOT(clientNotConnected()));

    }
}


void MainWindow::clientSendMess()
{
    if(mClient == NULL)
        return;

    mClient->sendMessage(ui->textMessage->text());
    ui->textMessage->clear();
}

void MainWindow::clientConnected()
{
    ui->pbConnexion->setDisabled(true);
    ui->pbEnvoyerPiece->setDisabled(false);
}


void MainWindow::clientNotConnected()
{
    delete mClient;
    mClient = NULL;
}


void MainWindow::paintEvent(QPaintEvent *e)
{

    QPainter painter(this);

    // Définit de la couleur de fond
       painter.setBrush(QColor(255, 0, 0, 100));

    // Définition de la variable
    QPolygon PolygonL1;
    // Rajout de 1 point
    PolygonL1.putPoints(0, 1, 200, 150); //x, y
    PolygonL1.putPoints(1, 1, 250, 150);
    PolygonL1.putPoints(2, 1, 250, 250);
    PolygonL1.putPoints(3, 1, 300, 250);
    PolygonL1.putPoints(4, 1, 300, 300);
    PolygonL1.putPoints(5, 1, 200, 300);


    // On dessine le polygone définit plus haut
    painter.drawPolygon(PolygonL1, Qt::WindingFill);

    painter.end();

    QPainter painter4(this);

    // Définit de la couleur de fond
       painter4.setBrush(QColor(0, 0, 255, 100));

    // Définition de la variable
    QPolygon PolygonL2;
    // Rajout de 1 point
    PolygonL2.putPoints(0, 1, 50, 150); //x, y
    PolygonL2.putPoints(1, 1, 100, 150);
    PolygonL2.putPoints(2, 1, 100, 300);
    PolygonL2.putPoints(3, 1, 0, 300);
    PolygonL2.putPoints(4, 1, 0, 250);
    PolygonL2.putPoints(5, 1, 50, 250);


    // On dessine le polygone définit plus haut
    painter4.drawPolygon(PolygonL2, Qt::WindingFill);

    painter4.end();


    QPainter painter2(this);

    // Définit de la couleur de fond
       painter2.setBrush(QColor(255, 0, 255, 100));

    // Définition de la variable
    QPolygon PolygonCarre;
    // Rajout de 1 point
    PolygonCarre.putPoints(0, 1, 400, 200); //x, y
    PolygonCarre.putPoints(1, 1, 400, 300);

    PolygonCarre.putPoints(2, 1, 500, 300);
    PolygonCarre.putPoints(3, 1, 500, 200);


    // On dessine le polygone définit plus haut
    painter2.drawPolygon(PolygonCarre, Qt::WindingFill);

    painter2.end();


    QPainter painter3(this);

    // Définit de la couleur de fond
       painter3.setBrush(QColor(253, 108, 158, 100));

    // Définition de la variable
    QPolygon PolygonRectangle;
    // Rajout de 1 point
    PolygonRectangle.putPoints(0, 1, 600, 100); //x, y
    PolygonRectangle.putPoints(1, 1, 650, 100);

    PolygonRectangle.putPoints(2, 1, 650, 300);
    PolygonRectangle.putPoints(3, 1, 600, 300);


    // On dessine le polygone définit plus haut
    painter3.drawPolygon(PolygonRectangle, Qt::WindingFill);

    painter3.end();


    QPainter painter5(this);

    // Définit de la couleur de fond
       painter5.setBrush(QColor(46, 0, 108, 100));

    // Définition de la variable
    QPolygon PolygonL3;
    // Rajout de 1 point
    PolygonL3.putPoints(0, 1, 0, 400); //x, y
    PolygonL3.putPoints(1, 1, 50, 400);
    PolygonL3.putPoints(2, 1, 50, 350);
    PolygonL3.putPoints(3, 1, 100, 350);
    PolygonL3.putPoints(4, 1, 100, 400); //x, y
    PolygonL3.putPoints(5, 1, 150, 400);
    PolygonL3.putPoints(6, 1, 150, 450);
    PolygonL3.putPoints(7, 1, 0, 450);


    // On dessine le polygone définit plus haut
    painter5.drawPolygon(PolygonL3, Qt::WindingFill);

    painter5.end();

    QPainter painter6(this);

    // Définit de la couleur de fond
       painter6.setBrush(QColor(237, 127, 16, 100));

    // Définition de la variable
    QPolygon PolygonZ1;
    // Rajout de 1 point
    PolygonZ1.putPoints(0, 1, 200, 350); //x, y
    PolygonZ1.putPoints(1, 1, 300, 350);
    PolygonZ1.putPoints(2, 1, 300, 400);
    PolygonZ1.putPoints(3, 1, 350, 400);
    PolygonZ1.putPoints(4, 1, 350, 450); //x, y
    PolygonZ1.putPoints(5, 1, 250, 450);
    PolygonZ1.putPoints(6, 1, 250, 400);
    PolygonZ1.putPoints(7, 1, 200, 400);


    // On dessine le polygone définit plus haut
    painter6.drawPolygon(PolygonZ1, Qt::WindingFill);

    painter6.end();


    QPainter painter7(this);

    // Définit de la couleur de fond
       painter7.setBrush(QColor(0, 255, 0, 100));

    // Définition de la variable
    QPolygon PolygonZ2;
    // Rajout de 1 point
    PolygonZ2.putPoints(0, 1, 450, 400); //x, y
    PolygonZ2.putPoints(1, 1, 500, 400);
    PolygonZ2.putPoints(2, 1, 500, 350);
    PolygonZ2.putPoints(3, 1, 600, 350);
    PolygonZ2.putPoints(4, 1, 600, 400); //x, y
    PolygonZ2.putPoints(5, 1, 550, 400);
    PolygonZ2.putPoints(6, 1, 550, 450);
    PolygonZ2.putPoints(7, 1, 450, 450);


    // On dessine le polygone définit plus haut
    painter7.drawPolygon(PolygonZ2, Qt::WindingFill);

    painter7.end();


}
