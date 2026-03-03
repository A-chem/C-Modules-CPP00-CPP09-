#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

#include <stdint.h>

struct Data
{
    int nb;
    std::string s;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif