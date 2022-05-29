#ifndef ITERATORFORRBTREE

#pragma once

using namespace std;
template <class typeKey>
class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};
#endif // !ITERATORFORRBTREE