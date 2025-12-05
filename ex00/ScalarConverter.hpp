#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static char charConvert(const std::string& literal);
		static int intConvert(const std::string& literal);
		static float floatConvert(const std::string& literal);
		static double doubleConvert(const std::string& literal);
		static void convert(const std::string& literal);
};


#endif