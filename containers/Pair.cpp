#include "Pair.h"

template <class T, class B>
Pair<T, B>::Pair(T first, B second) : _first(first), _second(second) {}

template <class T, class B>
Pair<T, B>::~Pair() {
	std::cout << "delete pair" << std::endl;
}

template <class T, class B>
std::ostream& operator<<(std::ostream &os, const Pair<T, B> &p) {
	os << "first: " << p._first << "second: " << p._second << std::endl;
	return os;
}