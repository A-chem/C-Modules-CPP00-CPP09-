#include "Serialization.hpp"

int main()
{

    Data data ;
    data.nbr = 42;
    data.str = "Hello 42";

    std::cout << "Original pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw->nbr << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "Serialization and deserialization work!" << std::endl;
    else
        std::cout << "Something went wrong!" << std::endl;

    std::cout << "Data content: " << ptr->nbr << ", " << ptr->str << std::endl;

 
    

    return 0;
}
