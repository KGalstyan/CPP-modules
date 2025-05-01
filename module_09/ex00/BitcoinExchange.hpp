#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        void loadDatabase(const std::string& filename);
        void addToDatabase(const std::string& date, const std::string& exStr);
        void processInput(const std::string& inputFile);
        void handleLine(const std::string& line);
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& valueStr, float& value);
        std::map<std::string, double>::iterator findClosestDate(const std::string& date);

    private:
        std::map<std::string, double> exDB;
};

#endif