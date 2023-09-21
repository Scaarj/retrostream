#pragma once

#include "drivers/Driver.h"

namespace drivers {
class MemoryDriver : public Driver {
public:
	virtual QString create(QString table, QVariantMap variantMap) override;
	virtual QVariantMap read(QString table, QString id) override;
	virtual QList<QVariantMap> readAll(QString table) override;
	virtual bool update(QString table, QString id, QVariantMap variantMap) override;
	virtual bool remove(QString table, QString id) override;
	virtual bool removeAll(QString table) override;
	virtual int size(QString table) override;
	virtual QString getId(QString table) override;

private:
	int index = 0;
	QMap<int, QVariantMap> records;
};
} // namespace drivers
