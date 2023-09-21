#pragma once

#include <QString>
#include <vector>

template <typename T, typename S = std::vector<T>>
class AbstractRepository {
public:
	virtual void create(T object) = 0;
	virtual void create(S objects) = 0;
	virtual T read(QString id) = 0;
	virtual S read(std::vector<QString> ids) = 0;
	virtual S readAll() = 0;
	virtual void update(T object) = 0;
	virtual void update(S objects) = 0;
	virtual void remove(QString id) = 0;
	virtual void remove(std::vector<QString> ids) = 0;
	virtual void remove(T object) = 0;
	virtual void remove(S objects) = 0;
	virtual void removeAll() = 0;
	virtual int count() = 0;
};
