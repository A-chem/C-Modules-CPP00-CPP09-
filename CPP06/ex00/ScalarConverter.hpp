#ifndef SCALARCONVERTER_HPP
#define  SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include <stdlib.h>
#include <iomanip>
#include <limits>
#include <cerrno>


enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID,
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        public:
            static void convert(const std::string& literal);
};

#endif