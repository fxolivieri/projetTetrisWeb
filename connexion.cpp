#include "connexion.h"

connexion::connexion(QUrl url, int iPort, QObject *parent): QTcpSocket(parent)
{
    QObject::connect(this,SIGNAL(error( QAbstractSocket::SocketError)),this,SLOT(ServerError(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(readyRead()), this, SLOT(messageReceived()));

    this->connectToHost(url,iPort);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(syncRequestFinished(QNetworkReply*)));


}




connexion::~connexion()
{

}

void connexion::ServerError(QAbstractSocket::SocketError error)
{
    QMessageBox::critical(0, "Client","Probleme de connexion");
    emit clientError();
}

void connexion::sendMessage(QByteArray data)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    data = QtJson::Json::serialize(collectSyncData());
    manager->post(request, data);


}

/*
void connexion::doConnect()
{
    socket = new connexion(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    // this is not blocking call
    socket->connectToHost("http://127.0.0.1/", 80);

    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void connexion::connected()
{
    qDebug() << "connected...";

    // Hey server, tell me about you.
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}


void connexion::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void connexion::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << socket->readAll();
}
*/
/*
QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(syncRequestFinished(QNetworkReply*)));

    QByteArray data = QtJson::Json::serialize(collectSyncData());

    // FIXME for debug
    qDebug() << "Sync" << QString::fromUtf8(data.data(), data.size());

    manager->post(request, data);
*/
