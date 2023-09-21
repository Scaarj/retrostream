#include "Author.h"

using namespace data;

Author::Author(QString name) : name(name) {
}

Author::Author(Id id, QString name) : Base(id), name(name) {
}
