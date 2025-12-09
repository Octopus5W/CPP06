#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "exemple: ./converter <literal>" << std::endl;
		return 1;
	}
	std::cout << static_cast<float>(11) << std::endl;
	ScalarConverter::convert(argv[1]);
	return 0;
}