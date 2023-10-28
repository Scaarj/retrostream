#pragma once

#include <QImage>
#include <QString>

#include "data/Author.h"

namespace data {
class Game : public Base {
public:
	Game() = default;
	Game(Author author, QString name, QString description, QImage preview);
	Game(Id id, Author author, QString name, QString description, QImage preview);

public:
	Author author;
	QString name;
	QString description;
	QImage preview;
};
} // namespace data
