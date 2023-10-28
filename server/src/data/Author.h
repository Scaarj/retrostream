#pragma once

#include <QString>

#include "data/Base.h"

namespace data {
class Author : public Base {
public:
	Author() = default;
	Author(QString name);
	Author(Id id, QString name);

public:
	QString name;
};
} // namespace data
