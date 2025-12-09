#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <sstream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static std::string is_nan_inf(const std::string& literal);
		static void charConvert(const std::string& literal);
		static void intConvert(const std::string& literal);
		static void floatConvert(const std::string& literal);
		static void doubleConvert(const std::string& literal);
		static void convert(const std::string& literal);
};


#endif