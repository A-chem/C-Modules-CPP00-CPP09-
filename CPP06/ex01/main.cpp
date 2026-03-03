#include "Serialization.hpp"

int main()
{
    Data d;
    d.nb = 42;
    d.s = "Abdilah";

    std::cout << "Original pointer: " << &d << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    
    Data* new_ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << new_ptr << std::endl;

    std::cout << "Value: " << new_ptr->s << ", Name: " << new_ptr->nb << std::endl;

    return 0;
}