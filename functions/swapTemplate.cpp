#include <iostream>

template<typename T, typename B>
void swap(T &a, B &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int x = 10, y = 20;
	swap(x, y);
	std::cout << x << " " << y << std::endl;

	long long z = 10, w = 20;
	swap(z, w);
	std::cout << z << " " << w << std::endl;

	char c = 'a', d = 'b';
	swap(c, d);
	std::cout << c << " " << d << std::endl;

	return 0;
}