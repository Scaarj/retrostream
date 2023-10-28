#include "Id.h"

using namespace data;

data::Id::Id() : value("") {
}

Id::Id(QString id) : value(id) {
}

Id::Id(int id) : value(QString::number(id)) {
}

bool Id::operator==(const Id& other) const {
	return value == other.value;
}

bool data::Id::valid() const {
	return value != "";
}
