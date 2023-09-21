#pragma once

#include <QList>
#include <QVariantMap>

namespace drivers {
class Driver {
public:
	virtual QString create(QString table, QVariantMap variantMap) = 0;
	virtual QVariantMap read(QString table, QString id) = 0;
	virtual QList<QVariantMap> readAll(QString table) = 0;
	virtual bool update(QString table, QString id, QVariantMap variantMap) = 0;
	virtual bool remove(QString table, QString id) = 0;
	virtual bool removeAll(QString table) = 0;
	virtual int size(QString table) = 0;
	virtual QString getId(QString table) = 0;
};
} // namespace drivers
