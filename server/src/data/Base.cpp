#include "Base.h"

using namespace data;

Base::Base(const Id& id) : id(id) {
}

data::Base::Base(const QString& id) : id(id) {
}

bool data::Base::operator==(const Base& other) const {
	return id == other.id && id.valid() && other.id.valid();
}

bool data::Base::operator!=(const Base& other) const {
	return !operator==(other);
}
