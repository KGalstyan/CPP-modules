#include "iter.hpp"

template <typename T>
void print(const T& value)
{
    std::cout << value << " ";
}

class Mlass
{
    public:
        Mlass(int n = 42) : _n(n) {}
        int get() const{
            return _n;}
    private:
        int _n;
};

std::ostream& operator<<(std::ostream& os, const Mlass& obj)
{
    os << obj.get();
    return os;
}


int main()
{
    int intArr[] = {1, 2, 3, 4};
    std::cout << "Integers: ";
    iter(intArr, 4, print<int>);
    std::cout << std::endl;

    Mlass MlassArr1[3] = {Mlass(5), Mlass(10), Mlass(15)};
    Mlass MlassArr2[3];

    std::cout << "Mlass objects1: ";
    iter(MlassArr1, 3, print<Mlass>);
    std::cout << std::endl;

    std::cout << "Mlass objects2: ";
    iter(MlassArr2, 3, print<Mlass>);
    std::cout << std::endl;

    return 0;
}
