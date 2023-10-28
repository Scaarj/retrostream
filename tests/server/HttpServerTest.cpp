#include "../pch.h"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

#include "http/HttpServer.h"

using namespace http;

QNetworkAccessManager manager;

class HttpServerTest
	: public QCoreApplication
	, public ::testing::Test {
public:
	HttpServerTest() : QCoreApplication(argc, &argv) {
	}

	void SetUp() {
		auto port = server.listen(this->port);
		defaultPath = "http://localhost:" + QString::number(port);
	}

	void TearDown() {
	}

protected:
	HttpServer server;
	int port{10035};
	QString defaultPath;

	int argc = 0;
	char* argv = 0;
};

TEST(HttpServer, listen) {
	HttpServer server;
	auto port{16000};
	QString defaultPath;

	ASSERT_EQ(server.listen(port), port);
}

//TEST_F(HttpServerTest, getUnhandledPath) {
//	QNetworkRequest request(QUrl(defaultPath + "/someUnhandledPath"));
//	QNetworkReply* reply = manager.get(request);

//	QObject::connect(reply, &QNetworkReply::finished, [&]() {
//		EXPECT_EQ(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 404);
//		quit();
//	});

//	exec();
//}

TEST_F(HttpServerTest, getApiVersion) {
	QNetworkRequest request(QUrl(defaultPath + "/rest/api/version"));
	QNetworkReply* reply = manager.get(request);

	QObject::connect(reply, &QNetworkReply::finished, [&]() {
		EXPECT_EQ(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 200);
		auto version = QString(reply->readAll());
		EXPECT_TRUE(version.contains(QRegularExpression("^(\\d+.\\d+.\\d+)$")))
			<< "actual version: " + version.toStdString() + " , expected version in form: A.B.C";
		quit();
	});

	exec();
}

TEST_F(HttpServerTest, gameGameList) {
	QNetworkRequest request(
		QUrl(defaultPath + QString("/rest/api/games/list?count=%1&order=%2&limit=%3").arg(20).arg(true).arg(100)));
	request.setRawHeader("User-Agent", "My app name v0.1");
	request.setRawHeader("X-Custom-User-Agent", "My app name v0.1");
	request.setRawHeader("Content-Type", "application/json");
	QNetworkReply* reply = manager.get(request);

	QObject::connect(reply, &QNetworkReply::finished, [&]() {
		EXPECT_EQ(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 200);
		auto version = QString(reply->readAll());
		//		EXPECT_TRUE(version.contains(QRegularExpression("^(\\d+.\\d+.\\d+)$")))
		//			<< "actual version: " + version.toStdString() + " , expected version in form: A.B.C";
		quit();
	});

	exec();
}
