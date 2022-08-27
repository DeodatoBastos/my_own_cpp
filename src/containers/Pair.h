
#ifndef PAIR_H
#define PAIR_H

#include <iostream>
template<class T, class B> class Pair;
template <class T, class B>
std::ostream &operator<<(std::ostream &, const Pair<T, B> &);

template<class T, class B>
class Pair {
private:
	T _first;
	B _second;
public:
	Pair(T first, B second);
	~Pair();

	friend std::ostream &operator<< <T, B>(std::ostream&, const Pair<T, B>&);
};

#endif // end PAIR_H