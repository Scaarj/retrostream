#pragma once

#include "Driver.h"

namespace drivers {
class DatabaseDriver : public Driver {
public:
	DatabaseDriver();

	virtual QString create(QString table, QVariantMap variantMap) override;
	virtual QVariantMap read(QString table, QString id) override;
	virtual QList<QVariantMap> readAll(QString table) override;
	virtual bool update(QString table, QString id, QVariantMap variantMap) override;
	virtual bool remove(QString table, QString id) override;
	virtual bool removeAll(QString table) override;
	virtual int size(QString table) override;
	virtual QString getId(QString table) override;
};
} // namespace drivers
