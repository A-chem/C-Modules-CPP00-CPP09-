#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other   ) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string& literal)
{
    return(literal == "nan"  || literal == "+inf"  || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

static double pseudoValue(const std::string& literal) {
    if (literal == "nan" || literal == "nanf")
        return NAN;
    if (literal == "+inf" || literal == "+inff")
        return INFINITY;
    if (literal == "-inf" || literal == "-inff")
        return -INFINITY;
    return 0.0; 
}

static bool isChar(const std::string& literal)
{
        return(literal.length() == 1 &&  !std::isdigit(literal[0]));
}

static bool isInt(const std::string& literal)
{
    size_t i = 0;
    if(literal[i] == '-' || literal[i] == '+') i++;
    for(; i < literal.length(); i++)
        if(!isdigit(literal[i]))
            return(false);
    return (true);
}

static bool isFloat(const std::string& literal)
{
    if (literal[literal.size() - 1] != 'f') return false;
    return (literal.find('.') != std::string::npos );
}

static bool isDouble(const std::string& literal) 
{
    return (literal.find('.') != std::string::npos && literal[literal.size() - 1] != 'f');
}
void ScalarConverter::convert(const std::string& literal)
{
    double vl;
    
    if (isPseudoLiteral(literal))
        vl = pseudoValue(literal);
    else if (isChar(literal))
        vl = literal[0];
    else if (isInt(literal))
        vl = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    else if (isFloat(literal))
        vl = static_cast<double>(std::strtof(literal.c_str(), NULL));
    else if (isDouble(literal))
        vl = std::strtod(literal.c_str(), NULL);
    else 
        throw std::invalid_argument("Invalid literal");
    
    std::cout << "char: ";
    if (std::isnan(vl) || std::isinf(vl) || vl < 0 || vl > 127)
        std::cout << "impossible\n";
    else if (!isprint(static_cast<char>(vl)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(vl) << "'\n";

    std::cout << "int: ";
    if (std::isnan(vl) || std::isinf(vl) || vl > INT_MAX || vl < INT_MIN)
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(vl) << "\n";
    
    float f = static_cast<float>(vl);
    std::cout << "float: ";
    if (isnan(f))
        std::cout << "nanf\n";
    else if (isinf(f))
        std::cout << (f > 0 ? "+inff" : "-inff") << "\n";
    else
    {
        std::cout << f;
        if(f ==  static_cast<int>(f))
            std::cout << ".0";
        std::cout <<  "f\n";
    }
    
    std::cout << "double: ";
    if (isnan(vl))
        std::cout << vl << "\n";
    else if (isinf(vl))
        std::cout <<  vl << "\n";
    else
    {
        std::cout << vl;
        if(f ==  static_cast<int>(f))
            std::cout << ".0";
        std::cout <<  "\n";
    }
   
    
}