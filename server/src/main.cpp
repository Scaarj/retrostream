#include <QCoreApplication>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "GamesRepository.h"
#include "drivers/DatabaseDriver.h"
#include "http/HttpServer.h"

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	drivers::DatabaseDriver databaseDriver;
	http::HttpServer server;
	server.listen(10035);

	GamesRepository gamesRepository(databaseDriver);

	QNetworkAccessManager manager;
	QNetworkRequest request(QUrl("http://localhost:10035/myApi"));
	QNetworkReply* reply = manager.get(request);

	QObject::connect(reply, &QNetworkReply::finished, [&]() { qDebug() << "reply" << reply->readAll(); });

	return a.exec();
}
