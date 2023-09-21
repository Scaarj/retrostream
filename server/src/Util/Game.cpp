#include "Game.h"

using namespace data;

data::Game::Game(Author author, QString name, QString description, QImage preview)
	: author(author)
	, name(name)
	, description(description)
	, preview(preview) {
}

Game::Game(Id id, Author author, QString name, QString description, QImage preview)
	: Base(id)
	, author(author)
	, name(name)
	, description(description)
	, preview(preview) {
}
