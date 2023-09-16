#pragma once

#include <QString>
#include <vector>

template <typename T, typename S = std::vector<T>>
class AbstractRepository {
public:
	virtual void save(T object) = 0;
	virtual void save(S ojbects) = 0;
	virtual void remove(T object) = 0;
	virtual void remove(S objects) = 0;
	virtual S& all() const = 0;
	virtual T find(QString id) = 0;
	virtual void clear() = 0;
	virtual int count() = 0;

protected:
	mutable S container;
};
