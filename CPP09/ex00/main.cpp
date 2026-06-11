#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    try
    {
        if(ac != 2)
            throw std::runtime_error("Error");
        BitcoinExchange btc;
        btc.loadDB();
        btc.processInp(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}