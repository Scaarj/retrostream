#include <QCoreApplication>

#include "GamesRepository.h"
#include "drivers/DatabaseDriver.h"

int main(int argc, char* argv[]) {
	QCoreApplication a(argc, argv);

	drivers::DatabaseDriver databaseDriver;

	GamesRepository gamesRepository(databaseDriver);

	return a.exec();
}
