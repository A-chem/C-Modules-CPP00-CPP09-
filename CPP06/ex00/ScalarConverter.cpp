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



static int isNumeric(const std::string& lt)
{
    for(size_t i = 0; i < lt.size(); i++)
        if(!isdigit(lt[i]) && lt[i] != 'f' && lt[i] != '.' && lt[0] != '-' && lt[0] != '0')
            return (0);
    return (1);
}

static LiteralType DetectType(const std::string& lt)
{
    if (lt.length() == 3 && lt[0] == '\'' && lt[2] == '\'')
        return CHAR;
    const std::string arr[] = {"nan", "nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff"};
    for(int i = 0; i < 8; i++)
        if(lt == arr[i])
            return PSEUDO;
    if(isNumeric(lt))
    {
        if(lt[lt.size() - 1] == 'f' && lt.find('.') != std::string::npos)
            return FLOAT;
        if(lt.find('.') != std::string::npos)
            return DOUBLE;
        char *endptr;
        std::strtol(lt.c_str(), &endptr, 10);
        if(*endptr == '\0')
            return INT;
    }
    return INVALID;
}

static void printFormChar(const std::string& lt)
{
    char c = lt[1];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) 
        << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(c) << std::endl;
}
static void printFormInt(const std::string& lt)
{
    errno = 0;
    long long n = std::strtoll(lt.c_str(), NULL, 10);
    if( n >= -128 && n <= 127)
    {
        if(isprint(static_cast<unsigned char>(n)))
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        else  std::cout << "char: Non displayable" << std::endl;
    }
    else std::cout << "char: impossible" << std::endl;
    if(errno == ERANGE || n < -2147483648 || n > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(n) << std::endl;
}

static void printFormPseudo(const std::string& lt)
{
    if (lt == "nanf" || lt == "+inff" || lt == "-inff" ||
        lt == "nan"  || lt == "+inf"  || lt == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int:  impossible" << std::endl;

    }
    if (lt == "nan" || lt == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		
	}
     if (lt == "+inf" || lt == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
    if (lt == "-inf" || lt == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static void printFormFloat(const std::string& lt)
{
    errno = 0;
    float f = std::strtof(lt.c_str(), NULL);
    if( f >= -128 && f <= 127)
    {
        if(isprint(static_cast<unsigned char>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else  std::cout << "char: Non displayable" << std::endl;
    }
    else std::cout << "char: impossible" << std::endl;
    if(f < -2147483648 || f > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << static_cast<double>(f) << std::endl;


}

static void printFormDouble(const std::string& lt)
{
    errno = 0;
    float d = std::strtod(lt.c_str(), NULL);
    if(d >= -128 && d <= 127)
    {
        if(isprint(static_cast<unsigned char>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else  std::cout << "char: Non displayable" << std::endl;
    }
    else std::cout << "char: impossible" << std::endl;
    if(d < -2147483648 || d > 2147483647 )
        std::cout << "int: impossible" << std::endl;
    else std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
        << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
        << d << std::endl;   
}
void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = DetectType(literal);
    switch (type)
    {
    case CHAR:
    {
        printFormChar(literal);
        break;
    }
    case INT:
    {
       printFormInt(literal);
       break;
    }
    case FLOAT:
    {
        printFormFloat(literal);
        break;
    }
    case DOUBLE:
    {
        printFormDouble(literal);
        break;
    }
    case  PSEUDO:
    {
        printFormPseudo(literal);
        break;
    }
    case INVALID:
    {
        throw std::runtime_error("Invalid Argument");
        break;
    }
    default:
        break;
    }
}