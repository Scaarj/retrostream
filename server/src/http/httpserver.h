#pragma once

#include <QHttpServer>

#define MAJOR 1
#define MINOR 0
#define BUILD 0

namespace http {
class HttpServer : public QObject {
public:
	HttpServer();

	int listen(int port = 0);

private:
	QHttpServer httpServer;
};
} // namespace http
