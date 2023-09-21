#pragma once

#include "Id.h"

namespace data {
class Base {
public:
	Base() = default;
	Base(const Id& id);
	Base(const QString& id);

	bool operator==(const Base& other) const;
	bool operator!=(const Base& other) const;

public:
	Id id;
};
} // namespace data
