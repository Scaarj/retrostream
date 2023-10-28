#include "httpserver.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QString>

using namespace http;

HttpServer::HttpServer() {
	QJsonArray myData;

	httpServer.route(
		"/rest/api/version", QHttpServerRequest::Method::Get, [&myData](const QHttpServerRequest& request) {
			QString versionString =
				QString("%1.%2.%3").arg(QString::number(MAJOR), QString::number(MINOR), QString::number(BUILD));
			return QHttpServerResponse(versionString);
		});

	httpServer.route(
		"/rest/api/games/list", QHttpServerRequest::Method::Get, [&myData](const QHttpServerRequest& request) {
			qDebug() << "querry: " << request.query().toString() << "url: " << request.url()
					 << "headers: " << request.headers() << " bodies: " << request.body();
			QString versionString =
				QString("%1.%2.%3").arg(QString::number(MAJOR), QString::number(MINOR), QString::number(BUILD));
			return QHttpServerResponse(versionString);
		});
}

int HttpServer::listen(int port) {
	return httpServer.listen(QHostAddress::Any, port);
}
