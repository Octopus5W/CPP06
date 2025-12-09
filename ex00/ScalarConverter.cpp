#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool check_sign(const std::string& literal) {
    size_t first = literal.find_first_of("+-");
    size_t last = literal.find_last_of("+-");
    if(first == last && (first == 0 || first == std::string::npos))
        return true;
    return false;
}

bool is_number(const std::string& literal) {
    size_t first_f = literal.find_first_of("f");
    size_t last_f = literal.find_last_of("f");
    size_t first_dot = literal.find_first_of(".");
    size_t last_dot = literal.find_last_of(".");

    if(literal.find_first_not_of("0123456789+-.f") == std::string::npos &&
        first_f == last_f && (last_f == literal.length() - 1 || last_f == std::string::npos) &&
        first_dot == last_dot)
    {
        if (first_f != std::string::npos && first_dot == std::string::npos)
            return false;
        else
            return true;
    }
    return false;
}

std::string ScalarConverter::is_nan_inf(const std::string& literal) {
    if (literal == "nan" || literal == "nanf")
        return "nan";
    else if (literal == "+inf" || literal == "+inff")
        return "+inf";
    else if (literal == "-inf" || literal == "-inff")
        return "-inf";
    return "false";
}

void ScalarConverter::charConvert(const std::string& literal) {
    if (literal.length() != 1 || (literal.length() == 3 && literal[0] != '\'' && literal[2] != '\'')) 
        std::cout << "impossible";
    else if (literal.length() == 1 && (literal[0] < 32 || literal[0] == 127)) 
        std::cout << "Non displayable";
    else if (literal.length() == 3) 
        std::cout << "'" << static_cast<char>(literal[1]) << "'";
    else
        std::cout << "'" << static_cast<char>(literal[0]) << "'";
}

void ScalarConverter::intConvert(const std::string& literal) {
    if (!check_sign(literal) || !is_number(literal))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(std::stoi(literal));
}

void ScalarConverter::floatConvert(const std::string& literal) {
    if (!check_sign(literal) || !is_number(literal))
        std::cout << "impossible";
    else
    {
        std::stringstream ss;

        ss << std::stof(literal);
        std::string stof_literal = ss.str();

        std::cout << static_cast<float>(std::stof(literal)) << (stof_literal.find_first_of('.') == std::string::npos ? ".0f" : "f");
    }
}

void ScalarConverter::doubleConvert(const std::string& literal) {
    if (!check_sign(literal) || !is_number(literal))
        std::cout << "impossible";
    else
        std::cout << static_cast<double>(std::stod(literal));
}

void ScalarConverter::convert(const std::string& literal) {
    std::string special = is_nan_inf(literal);
    if (special != "false") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" <<  std::endl;
        std::cout << "float: " << special << "f" << std::endl;
        std::cout << "double: " << special << std::endl;
    }
    else {
        std::cout << "char: ";
        charConvert(literal);
        std::cout << std::endl;

        std::cout << "int: ";
        intConvert(literal);
        std::cout << std::endl;

        std::cout << "float: ";
        floatConvert(literal);
        std::cout << std::endl;

        std::cout << "double: ";
        doubleConvert(literal);
        std::cout << std::endl;
    }
}