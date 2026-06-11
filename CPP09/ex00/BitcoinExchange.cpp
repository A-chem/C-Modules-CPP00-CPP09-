#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::loadDB()
{
    std::ifstream file("data.csv");
    if(!file.is_open())
        throw std::runtime_error("database error");
    std::string line;
    getline(file, line);
    while(getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price;
        getline(ss, date, ',');
        getline(ss, price);
        db[date] = atof(price.c_str());
    }
}

static std::string trim(std::string s)
{
    size_t start = 0;
    while(start < s.length() && std::isspace(s[start]))
        start++;
    size_t end = s.length();
    while(end > start && std::isspace(s[end - 1]))
        end--;
    return s.substr(start, end - start);
}

static bool validDate(std::string d)
{
    if (d.length() != 10 || d[4] != '-' || d[7] != '-')
    {
        std::cerr << "Error: bad input =>" << d << std::endl;
        return false;
    }
    for(int i = 0; i < d.length(); i++)
    {
        if(i == 4 || i == 7)
            continue ;
        if(!isdigit(d[i]))
        {
            std::cerr << "Error: bad input =>" << d << std::endl;
            return false;
        }
    }
    int year = atoi(d.substr(0, 4).c_str());
    int month = atoi(d.substr(5, 2).c_str());
    int day = atoi(d.substr(8, 2).c_str());
    int daysMonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    if(month < 1 || month > 12  || day < 1 || day > daysMonth[month - 1]) 
    {
        std::cerr << "Error: bad input =>" << d << std::endl;
        return false; 
    }
    return true;
}

static bool validValue(std::string vl)
{
    if(vl.empty())
    {
        std::cout<< "Error: bad input => " << vl <<  std::endl;
        return false;
    }
    int dots = 0;
    for(int i = 0; i < vl.length(); i++)
    {
        
        if (vl[i] == '.')
        {
            dots++;
            if(dots > 1)
            {
                std::cout<< "Error: bad input => " << vl << std::endl;
                return false;
            }
        }
        else if(!isdigit(vl[i]))
        {
            if(vl[0] == '-')
                std::cout << "Error: not a positive number." <<  std::endl;
            else
                std::cout<< "Error: bad input => " << vl <<  std::endl;
            return false;   
        }
    }
    return true;
}
void BitcoinExchange::processInp(std::string f)
{
    std::ifstream file(f.c_str());
    if(!file.is_open())
        throw std::runtime_error("input error");
    std::string line;
    getline(file, line);
    while(getline(file, line))
    {
        size_t pos = line.find('|');
        if(pos == std::string::npos)
        {
            std::cout<< "Error: bad input => " << line <<  std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string vl = line.substr(pos + 1);
        
        if (!validDate(trim(date)) || !validValue(trim(vl)))
            continue ;
        double nbr = atof(trim(vl).c_str());
        if (static<long double>(nbr) > std::numeric_limits<int>::max())
        {
            std::cout << "Error: too large number."
                      << std::endl;
            continue;
        }
        std::cout << nbr <<std::endl;
        
    }
}