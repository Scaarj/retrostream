#pragma once

#include <QImage>
#include <QString>

#include "Util/Author.h"

namespace util {
class Game
{
public:
	Game();

	bool operator==(const Game& other) const {
		return id == other.id && name == other.name;
	}

	bool operator!=(const Game& other) const {
		return !operator==(other);
	}

public:
	Id id;
	Author author;
	QString name;
	QString description;
	QImage preview;
};
} // namespace util
