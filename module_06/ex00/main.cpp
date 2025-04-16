#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Wrong number of arguments!\n";
		return 1;
    }
    (void)argv;
    ScalarConverter::convert(argv[1]);
}