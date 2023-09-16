#include "../pch.h"

#include "GamesRepository.h"

using namespace util;

TEST(GamesRepository, save_and_check_count) {
	GamesRepository repository;

	ASSERT_EQ(repository.count(), 0);
	repository.save(Game());
	ASSERT_EQ(repository.count(), 1);
}

TEST(GamesRepository, save_and_check_equal) {
	GamesRepository repository;

	ASSERT_TRUE(repository.all() == (GamesRepository::ContainerType{}));
	repository.save(Game());
	repository.save(Game());
	ASSERT_TRUE(repository.all() == (GamesRepository::ContainerType{Game(), Game()}));
}
