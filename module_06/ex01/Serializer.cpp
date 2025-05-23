#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(std::string& smth)
{
    (void)smth;
}

Serializer::Serializer(Serializer& obj)
{
    *this = obj;
}

Serializer& Serializer::operator=(Serializer& obj)
{
    if(this != &obj)
    {
        *this = obj;
    }
    return(*this);
}

Serializer::~Serializer()
{
}
uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}
