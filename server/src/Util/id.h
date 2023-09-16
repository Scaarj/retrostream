#pragma once

#include <QString>

namespace util {
class Id
{
public:
	Id();

	bool operator==(const Id& other) const {
		return id == other.id;
	}

public:
	QString id;
};
} // namespace util
