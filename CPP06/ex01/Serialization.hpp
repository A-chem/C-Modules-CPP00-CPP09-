#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>

struct Data
{
    int nbr;
    std::string str;
};

class Serializer
{
private:
    Serializer(); 
    ~Serializer(); 
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif