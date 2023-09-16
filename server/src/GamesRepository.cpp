#include "GamesRepository.h"

using namespace util;

GamesRepository::GamesRepository() {
}

void GamesRepository::save(Type object) {
	container.push_back(object);
}

void GamesRepository::save(ContainerType ojbects) {
}

void GamesRepository::remove(Type object) {
}

void GamesRepository::remove(ContainerType objects) {
}

GamesRepository::ContainerType& GamesRepository::all() const {
	return container;
}

GamesRepository::Type GamesRepository::find(QString id) {
	return Game();
}

void GamesRepository::clear() {
	container.clear();
}

int GamesRepository::count() {
	return container.size();
}
