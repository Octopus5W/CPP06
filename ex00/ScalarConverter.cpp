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
        if ((literal.find_first_of("+-.f") != std::string::npos && 
            literal.find_first_of("0123456789") == std::string::npos) ||
            (first_f != std::string::npos && first_dot == std::string::npos))
            return false;
        else
            return true;
    }
    return false;
}

bool is_nan_inf(const std::string& literal) {
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" <<  std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
        return true;
    }
    else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" <<  std::endl;
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
        return true;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" <<  std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
        return true;
    }
    return false;
}

void ScalarConverter::charConvert(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') 
        std::cout << "'" << static_cast<char>(literal[1]) << "'";
    else if (check_sign(literal) && is_number(literal))
    {
        double num = std::strtod(literal.c_str(), NULL);

        if (std::isprint(static_cast<char>(num)))
            std::cout << "'" << static_cast<char>(num) << "'";
        else
            std::cout << "impossible";
    }
    else
        std::cout << "impossible";
}

void ScalarConverter::intConvert(const std::string& literal) {
    double num = std::strtod(literal.c_str(), NULL);

    if (!check_sign(literal) || !is_number(literal)
        || num < std::numeric_limits<int>::lowest() || num > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(num);
}

void ScalarConverter::floatConvert(const std::string& literal) {
    
    if (!check_sign(literal) || !is_number(literal))
        std::cout << "impossible";
    else
    {
        double num = std::strtod(literal.c_str(), NULL);

        if (num < std::numeric_limits<float>::lowest() || num > std::numeric_limits<float>::max())
        {
            std::cout << static_cast<float>(num) << "f";
            return;
        }
        std::cout.precision(6);
        std::cout << static_cast<float>(num) << (literal.find_first_of('.') == std::string::npos ? ".0f" : "f");
    }
}

void ScalarConverter::doubleConvert(const std::string& literal) {
    
    if (!check_sign(literal) || !is_number(literal))
        std::cout << "impossible";
    else
    {
        double num = std::strtod(literal.c_str(), NULL);
        if (num < std::numeric_limits<double>::lowest() || num > std::numeric_limits<double>::max())
        {
            std::cout << static_cast<double>(num);
            return;
        }
        std::cout.precision(15);
        std::cout << static_cast<double>(num) << (literal.find_first_of('.') == std::string::npos ? ".0" : "");
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.length() > 3 && literal[0] == '\'' && literal[literal.length() - 1] == '\'')
    {
        if (literal == "'nan'" || literal == "'nanf'")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" <<  std::endl;
            std::cout << "float: " << "nanf" << std::endl;
            std::cout << "double: " << "nan" << std::endl;
        }
        else if (literal == "'+inf'" || literal == "'+inff'" || literal == "'inf'" || literal == "'inff'")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" <<  std::endl;
            std::cout << "float: " << "+inff" << std::endl;
            std::cout << "double: " << "+inf" << std::endl;
        }
        else if (literal == "'-inf'" || literal == "'-inff'")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" <<  std::endl;
            std::cout << "float: " << "-inff" << std::endl;
            std::cout << "double: " << "-inf" << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" <<  std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
    else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        std::cout << "char: ";
        charConvert(literal);
        std::cout << std::endl;
        std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[1]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[1]) << ".0" << std::endl;
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