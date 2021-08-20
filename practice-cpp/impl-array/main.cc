
#include <iostream>

#include "IVector.hpp"

int main(int argc, char* argv[]) {

	CI::IVector v(10);

	std::cout << "v.get_capacity(): " << v.get_capacity() << "\n";

	v.push(100);
	v.push(200);

	std::cout << "v.at(0) = " << v.at(0) << "\n";
	std::cout << "v.at(1) = " << v.at(1) << "\n";

	return 0;
}