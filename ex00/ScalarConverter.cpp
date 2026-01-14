#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void charConvert(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        std::cout << "'" << literal[0] << "'";
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        if (std::isprint(literal[1]))
            std::cout << "'" << literal[1] << "'";
        else
            std::cout << "Non displayable";
        return;
    }
    
    char* end;
    double num = std::strtod(literal.c_str(), &end);
    std::string suffix(end);

    if (suffix.length() > 1 || (suffix.length() == 1 && suffix[0] != 'f') || (literal.find_first_of("0123456789") == std::string::npos && literal != "nan" && literal != "+inf" && literal != "-inf" && literal != "nanf" && literal != "+inff" && literal != "-inff")) {
         std::cout << "impossible";
         return;
    }

    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") {
        std::cout << "impossible";
        return;
    }

    if (num < 0 || num > 127) {
        std::cout << "impossible";
    } else if (!std::isprint(static_cast<int>(num))) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << static_cast<char>(num) << "'";
    }
}

void intConvert(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        std::cout << static_cast<int>(literal[0]);
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        std::cout << static_cast<int>(literal[1]);
        return;
    }

    char* end;
    double num = std::strtod(literal.c_str(), &end);
    std::string suffix(end);

    if (suffix.length() > 1 || (suffix.length() == 1 && suffix[0] != 'f')) {
         if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") {
             std::cout << "impossible";
             return;
        }
        std::cout << "impossible";
        return;
    }
    
    if (num != num || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
         std::cout << "impossible";
         return;
    }
    
    std::cout << static_cast<int>(num);
}

void floatConvert(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        std::cout << static_cast<float>(literal[0]) << ".0f";
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        std::cout << static_cast<float>(literal[1]) << ".0f";
        return;
    }

    char* end;
    double num = std::strtod(literal.c_str(), &end);
    std::string suffix(end);

    if (suffix.length() > 1 || (suffix.length() == 1 && suffix[0] != 'f')) {
         if (literal == "nan" || literal == "nanf") {
            std::cout << "nanf";
            return;
        } else if (literal == "+inf" || literal == "+inff") {
            std::cout << "+inff";
            return;
        } else if (literal == "-inf" || literal == "-inff") {
            std::cout << "-inff";
            return;
        }
        std::cout << "impossible";
        return;
    }

    if (literal == "nan" || literal == "nanf") {
        std::cout << "nanf";
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "+inff";
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "-inff";
    } else {
        float f = static_cast<float>(num);
        std::cout << f;
        if (f == static_cast<long>(f))
             std::cout << ".0";
        std::cout << "f";
    }
}

void doubleConvert(const std::string& literal) {
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        std::cout << static_cast<double>(literal[0]) << ".0";
        return;
    }
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        std::cout << static_cast<double>(literal[1]) << ".0";
        return;
    }

    char* end;
    double num = std::strtod(literal.c_str(), &end);
    std::string suffix(end);

    if (suffix.length() > 1 || (suffix.length() == 1 && suffix[0] != 'f')) {
        if (literal == "nan" || literal == "nanf") {
            std::cout << "nan";
            return;
        } else if (literal == "+inf" || literal == "+inff") {
            std::cout << "+inf";
            return;
        } else if (literal == "-inf" || literal == "-inff") {
            std::cout << "-inf";
            return;
        }
        std::cout << "impossible";
        return;
    }

    if (literal == "nan" || literal == "nanf") {
        std::cout << "nan";
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "+inf";
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "-inf";
    } else {
        std::cout << num;
        if (num == static_cast<long>(num))
            std::cout << ".0";
    }
}

void ScalarConverter::convert(const std::string& literal) {
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
