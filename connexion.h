#ifndef CONNEXION_H
#define CONNEXION_H

#include <QTcpSocket>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QNetworkAccessManager>




class connexion : public QTcpSocket
{
    Q_OBJECT

public:


    connexion(QUrl url, int iPort, QObject *parent=0);
    virtual ~connexion();
    void sendMessage(QByteArray data);

private slots:
    void ServerError(QAbstractSocket::SocketError error);

signals:
    void clientError();


};

#endif // CONNEXION_H
