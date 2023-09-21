#pragma once

#include <QObject>
#include <QSqlDatabase>

class Database : public QObject {
public:
	Database();

private:
	QSqlDatabase db;
};
