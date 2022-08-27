
#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template <class T, class B>
class Pair {
private:
	T first;
	B second;

public:
	Pair(T First, B Second) : first(First), second(Second) {}
	~Pair() {}

	friend std::ostream &operator<<(std::ostream &os, const Pair<T, B> &p) {
		os << "(" << p.first << ", " << p.second << ")";
		return os;
	}
};

#endif // end PAIR_H