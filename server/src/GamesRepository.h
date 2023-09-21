#pragma once

#include <QVariantMap>

#include "AbstractRepository.h"
#include "Util/Game.h"

template <typename T>
class GamesRepository : public AbstractRepository<data::Game> {
public:
	const QString tableName = "Games";

	using Type = data::Game;
	using ContainerType = std::vector<Type>;

public:
	GamesRepository(T& driver) : driver(driver) {
	}
	~GamesRepository() {
	}
	GamesRepository(const GamesRepository&) = delete;
	GamesRepository& operator=(const GamesRepository&) = delete;

	virtual void create(Type object) override {
		driver.create(tableName, serialize(object));
	}
	virtual void create(ContainerType objects) override {
		for (const auto& it : objects) {
			create(it);
		}
	}
	virtual Type read(QString id) override {
		return deserialize(driver.read(tableName, id));
	}
	virtual ContainerType read(std::vector<QString> ids) override {
	}
	virtual ContainerType readAll() override {
		auto records = driver.readAll(tableName);

		ContainerType result;
		for (auto it : records) {
			result.push_back(deserialize(it));
		}
		return result;
	}
	virtual void update(Type object) override {
		driver.update(tableName, object.id.value, serialize(object));
	}
	virtual void update(ContainerType objects) override {
		for (const auto& it : objects) {
			update(it);
		}
	}
	virtual void remove(QString id) override {
		driver.remove(tableName, id);
	}
	virtual void remove(std::vector<QString> ids) override {
		for (const auto& it : ids) {
			remove(it);
		}
	}
	virtual void remove(Type object) override {
		remove(object.id.value);
	}
	virtual void remove(ContainerType objects) override {
		for (const auto& it : objects) {
			remove(it.id.value);
		}
	}
	virtual void removeAll() override {
		driver.removeAll(tableName);
	}
	virtual int count() override {
		return driver.size(tableName);
	}

private:
	Type deserialize(const QVariantMap& variantMap) {
		auto author = data::Author(data::Id(variantMap["author"].toMap()["id"].toMap()["value"].toString()),
			variantMap["author"].toMap()["name"].toString());
		auto objectId = data::Id(variantMap["id"].toMap()["id"].toString());
		auto result = Type(objectId, author, variantMap["name"].toString(), variantMap["description"].toString(),
			variantMap["preview"].template value<QImage>());

		return result;
	}

	QVariantMap serialize(const Type& object) {
		QVariantMap result;
		QVariantMap id;
		QVariantMap author;
		QVariantMap authorId;

		id["id"] = driver.getId(tableName);
		authorId["value"] = object.author.id.value;
		author["id"] = authorId;
		author["name"] = object.author.name;
		result["id"] = id;
		result["author"] = author;
		result["name"] = object.name;
		result["description"] = object.description;
		result["preview"] = object.preview;

		return result;
	}

private:
	T& driver;
};
