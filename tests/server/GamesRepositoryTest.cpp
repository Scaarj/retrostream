#include "../pch.h"

#include <QDebug>

#include "GamesRepository.h"
#include "drivers/MemoryDriver.h"

using namespace data;
using namespace drivers;

template <typename T, typename K>
bool contains(const T& container, K object) {
	return std::find_if(container.cbegin(), container.cend(),
			   [object](const data::Game& game) { return game.name == object.name; }) != container.cend();
}

template <typename T>
bool equal(const T& first, const T& second) {
	return first.name == second.name;
}

TEST(GamesRepository, Create) {
	MemoryDriver driver;
	GamesRepository repository(driver);

	ASSERT_EQ(repository.count(), 0);
	repository.create(Game(Author(Id("0"), "Author"), "Game", "Description", QImage()));
	ASSERT_EQ(repository.count(), 1);
}

TEST(GamesRepository, CreateAndRemoveAll) {
	MemoryDriver driver;
	GamesRepository repository(driver);

	ASSERT_EQ(repository.count(), 0);
	repository.create(Game(Author(Id("0"), "Author"), "Game", "Description", QImage()));
	ASSERT_EQ(repository.count(), 1);
	repository.removeAll();
	ASSERT_EQ(repository.count(), 0);
}

TEST(GamesRepository, CreateAndReadAll) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author("Author1"), "Game1", "Description", QImage());
	auto game2 = Game(Author("Author2"), "Game2", "Description", QImage());
	auto filledRepo = GamesRepository<MemoryDriver>::ContainerType{game1, game2};

	ASSERT_TRUE(repository.readAll() == GamesRepository<MemoryDriver>::ContainerType{});

	repository.create(game1);
	repository.create(game2);

	auto games = repository.readAll();

	ASSERT_TRUE(contains(games, game1));
	ASSERT_TRUE(contains(games, game2));
}

TEST(GameRepository, CreateList) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto g1 = Game(Author(Id("0"), "Author1"), "Game1", "Description1", QImage());
	auto g2 = Game(Author(Id("1"), "Author2"), "Game2", "Description2", QImage());
	auto gameList = {g1, g2};

	ASSERT_EQ(repository.count(), 0);
	repository.create(gameList);
	ASSERT_EQ(repository.count(), 2);
}

TEST(GameRepository, CreateListAndReadAll) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author(Id("0"), "Author1"), "Game1", "Description1", QImage());
	auto game2 = Game(Author(Id("1"), "Author2"), "Game2", "Description2", QImage());
	auto gameList = {game1, game2};

	repository.create(gameList);
	auto games = repository.readAll();

	ASSERT_TRUE(contains(games, game1));
	ASSERT_TRUE(contains(games, game2));
}

TEST(GameRepository, ReadId) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game = Game(Author(Id("1"), ""), "", "", QImage());

	repository.create(game);

	ASSERT_TRUE(repository.read(repository.readAll()[0].id.value).id.valid());
}

TEST(GameRepository, ReadIds) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author(Id("1"), ""), "", "", QImage());
	auto game2 = Game(Author(Id("2"), ""), "", "", QImage());
	auto game3 = Game(Author(Id("3"), ""), "", "", QImage());
	auto game4 = Game(Author(Id("4"), ""), "", "", QImage());

	repository.create({game1, game2, game3, game4});

	auto games = repository.readAll();
	std::vector<QString> ids;
	std::transform(
		games.cbegin(), games.cend(), std::back_inserter(ids), [](const data::Game game) { return game.id.value; });

	ASSERT_EQ(ids.size(), 4);
	for (const auto& it : ids) {
		ASSERT_TRUE(repository.read(it).id.valid());
	}
}

TEST(GameRepository, RemoveById) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game = Game(Author(Id("1"), ""), "", "", QImage());

	repository.create(game);

	auto id = repository.readAll()[0].id.value;

	ASSERT_EQ(repository.count(), 1);
	repository.remove(id);
	ASSERT_EQ(repository.count(), 0);
}

TEST(GameRepository, RemoveByIds) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author(Id("1"), ""), "", "", QImage());
	auto game2 = Game(Author(Id("2"), ""), "", "", QImage());
	auto game3 = Game(Author(Id("3"), ""), "", "", QImage());

	repository.create({game1, game2, game3});

	auto id1 = repository.readAll()[0].id.value;
	auto id2 = repository.readAll()[1].id.value;
	auto id3 = repository.readAll()[2].id.value;

	ASSERT_EQ(repository.count(), 3);
	repository.remove(id1);
	ASSERT_EQ(repository.count(), 2);
	repository.remove(id2);
	ASSERT_EQ(repository.count(), 1);
	repository.remove(id3);
	ASSERT_EQ(repository.count(), 0);
}

TEST(GameRepository, RemoveByObject) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game = Game(Author(Id("1"), ""), "", "", QImage());

	repository.create(game);

	auto object = repository.readAll()[0];

	ASSERT_EQ(repository.count(), 1);
	repository.remove(object);
	ASSERT_EQ(repository.count(), 0);
}

TEST(GameRepository, RemoveByObjects) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author(Id("1"), ""), "", "", QImage());
	auto game2 = Game(Author(Id("2"), ""), "", "", QImage());
	auto game3 = Game(Author(Id("3"), ""), "", "", QImage());

	repository.create({game1, game2, game3});

	auto object2 = repository.readAll()[1];
	auto object1 = repository.readAll()[0];
	auto object3 = repository.readAll()[2];

	ASSERT_EQ(repository.count(), 3);
	repository.remove(object1);
	ASSERT_EQ(repository.count(), 2);
	repository.remove(object2);
	ASSERT_EQ(repository.count(), 1);
	repository.remove(object3);
	ASSERT_EQ(repository.count(), 0);
}

TEST(GameRepository, UpdateObject) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game = Game(Author(Id("1"), ""), "Game", "", QImage());

	repository.create(game);
	auto object = repository.readAll()[0];

	ASSERT_STREQ(object.name.toStdString().c_str(), "Game");

	object.name = "NewGame";
	repository.update(object);
	object = repository.readAll()[0];

	ASSERT_STREQ(object.name.toStdString().c_str(), "NewGame");
}

TEST(GameRepository, UpdateObjects) {
	MemoryDriver driver;
	GamesRepository repository(driver);
	auto game1 = Game(Author(Id("1"), ""), "Game1", "", QImage());
	auto game2 = Game(Author(Id("2"), ""), "Game2", "", QImage());
	auto game3 = Game(Author(Id("3"), ""), "Game3", "", QImage());

	repository.create({game1, game2, game3});
	auto object1 = repository.readAll()[0];
	auto object2 = repository.readAll()[1];
	auto object3 = repository.readAll()[2];

	ASSERT_STREQ(object1.name.toStdString().c_str(), "Game1");
	ASSERT_STREQ(object2.name.toStdString().c_str(), "Game2");
	ASSERT_STREQ(object3.name.toStdString().c_str(), "Game3");

	object1.name = "NewGame1";
	object2.name = "NewGame2";
	object3.name = "NewGame3";
	repository.update({object1, object2, object3});
	object1 = repository.readAll()[0];
	object2 = repository.readAll()[1];
	object3 = repository.readAll()[2];

	ASSERT_STREQ(object1.name.toStdString().c_str(), "NewGame1");
	ASSERT_STREQ(object2.name.toStdString().c_str(), "NewGame2");
	ASSERT_STREQ(object3.name.toStdString().c_str(), "NewGame3");
}
