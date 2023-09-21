#include "MemoryDriver.h"

using namespace drivers;

QString MemoryDriver::create(QString table, QVariantMap variantMap) {
	records.insert(index, variantMap);
	index++;
	return QString::number(index);
}

QVariantMap MemoryDriver::read(QString table, QString id) {
	auto key = id.toInt();
	if (records.contains(key)) {
		auto record = records[key];
		return record;
	} else {
		return QVariantMap();
	}
}

QList<QVariantMap> MemoryDriver::readAll(QString table) {
	return records.values();
}

bool MemoryDriver::update(QString table, QString id, QVariantMap variantMap) {
	auto key = id.toInt();
	if (records.contains(key)) {
		records[key] = variantMap;
		return true;
	} else {
		return false;
	}
}

bool MemoryDriver::remove(QString table, QString id) {
	auto count = records.count();
	return count != records.removeIf([id](QMap<int, QVariantMap>::iterator it) {
		return (*it)["id"].toMap()["id"].toString() == id;
	});
}

bool MemoryDriver::removeAll(QString table) {
	records.clear();
	return records.size() == 0;
}

int MemoryDriver::size(QString table) {
	return records.size();
}

QString MemoryDriver::getId(QString table) {
	return QString::number(index);
}
