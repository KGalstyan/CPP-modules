#include "Serializer.hpp"

int main()
{
    Data original;
    original.id = 42;
    original.name = "TestObject";

    std::cout << "Original pointer:     " << &original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer:    " << recovered << std::endl;

    if (recovered == &original)
    {
        std::cout << "Success: Pointers match!" << std::endl;
        std::cout << "Recovered Data: id = " << recovered->id << ", name = " << recovered->name << std::endl;
    } else {
        std::cout << "Failure: Pointers do NOT match!" << std::endl;
    }

    return 0;
}
