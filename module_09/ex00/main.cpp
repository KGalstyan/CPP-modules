#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc == 1)
    {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
    if(argc > 2)
    {
		std::cerr << "Error: too many arguments." << std::endl;
		return 1;
	}
    try
    {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}