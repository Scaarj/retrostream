#include "DatabaseDriver.h"

using namespace drivers;

DatabaseDriver::DatabaseDriver()
{
}

QString DatabaseDriver::create(QString table, QVariantMap variantMap) {
}

QVariantMap DatabaseDriver::read(QString table, QString id) {
}

QList<QVariantMap> DatabaseDriver::readAll(QString table)
{
	
}

bool DatabaseDriver::update(QString table, QString id, QVariantMap variantMap) {
}

bool DatabaseDriver::remove(QString table, QString id) {
}

bool DatabaseDriver::removeAll(QString table)
{
	
}

int DatabaseDriver::size(QString table)
{
	
}

QString DatabaseDriver::getId(QString table) {
}
