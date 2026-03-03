#include "ScalarConverter.hpp"



int main ()
{
    try
    {
        std::string arg;
        std::getline(std::cin, arg);
        ScalarConverter::convert(arg);
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int:  impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double:  impossible" << std::endl;
    }
    
    
}