#include "createchannel.h"
#include "ui_createchannel.h"
#include "mainwindow.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

extern QString username,firstname,lastname,password,token;
extern QEventLoop eventLoop;//new
extern QNetworkAccessManager mgr;//new
createchannel::createchannel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createchannel)
{
    ui->setupUi(this);
}

createchannel::~createchannel()
{
    delete ui;
}

void createchannel::on_pushButton_create_channel_clicked()
{

    QString channel_name,channel_titel;
    channel_name=ui->lineEdit_channel_name->text();
    channel_titel=ui->lineEdit_channel_titel->text();
     QString code,message;
     QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
     QNetworkRequest req( QUrl( QString("http://api.barafardayebehtar.ml:8080/createchannel?token="+token+"&channel_name="+channel_name+"&channel_title="+channel_titel) ) );
     QNetworkReply *reply = mgr.get(req);
     eventLoop.exec(); // blocks stack until "finished()" has been called

     if (reply->error() == QNetworkReply::NoError) {

         QString strReply = (QString)reply->readAll();

         //parse json
         qDebug() << "Response:" << strReply;
         QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

         QJsonObject jsonObj = jsonResponse.object();
         code = jsonObj["code"].toString();
         message = jsonObj["message"].toString();


     }
     else {
         //failure
         qDebug() << "Failure" <<reply->errorString();
         delete reply;
     }
     hide();
     forget5 = new forgot(this, "createchannel",message);
     forget5->show();
     forget5->exec();
     hide();
     }

