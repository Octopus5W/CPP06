#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

char ScalarConverter::charConvert(const std::string& literal) {
    return static_cast<char>(std::stoi(literal));
}

int ScalarConverter::intConvert(const std::string& literal) {
    return static_cast<int>(std::stoi(literal));
}

float ScalarConverter::floatConvert(const std::string& literal) {
    return static_cast<float>(std::stof(literal));
}

double ScalarConverter::doubleConvert(const std::string& literal) {
    return static_cast<double>(std::stod(literal));
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << "Converting of scalar of " << literal << " :" << std::endl;
    std::cout << "char: " << charConvert(literal) << std::endl;
    std::cout << "int: " << intConvert(literal) << std::endl;
    std::cout << "float: " << floatConvert(literal) << std::endl;
    std::cout << "double: " << doubleConvert(literal) << std::endl;
}