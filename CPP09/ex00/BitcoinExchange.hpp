#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <limits>


class BitcoinExchange 
{
    private:
        std::map<std::string, double> db;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void loadDB();
        void processInp(std::string f);
};

#endif