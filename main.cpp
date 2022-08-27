#include <iostream>
#include "containers/Pair.h"

int main() {
	Pair<int, int> my_pair(2, 3);

	std::cout << my_pair;

	return 0;
}