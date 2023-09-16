#pragma once

#include "AbstractRepository.h"
#include "Util/Game.h"

class GamesRepository : public AbstractRepository<util::Game> {
public:
	using Type = util::Game;
	using ContainerType = std::vector<Type>;

public:
	GamesRepository();

public:
	virtual void save(Type object) override;
	virtual void save(ContainerType ojbects) override;
	virtual void remove(Type object) override;
	virtual void remove(ContainerType objects) override;
	virtual ContainerType& all() const override;
	virtual Type find(QString id) override;
	virtual void clear() override;
	virtual int count() override;
};
