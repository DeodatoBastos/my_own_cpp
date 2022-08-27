#include <iostream>
#include "classes/Complex.h"

int main() {
	Complex<double> z(1, 2);

	std::cout << z << std::endl;

	return 0;
}