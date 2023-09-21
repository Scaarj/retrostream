#pragma once

#include <QString>

namespace data {
class Id {
public:
	Id();
	Id(QString id);
	Id(int id);

	bool operator==(const Id& other) const;
	bool valid() const;

public:
	QString value;
};
} // namespace util
