#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    this->exDB = obj.exDB;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if(this != &obj)
    {
        this->exDB = obj.exDB;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, exStr;
        if (std::getline(ss, date, ',') && std::getline(ss, exStr))
            addToDatabase(date, exStr);
    }
}

void BitcoinExchange::addToDatabase(const std::string& date, const std::string& exStr)
{
    std::stringstream ss(exStr);
    double ex;
    ss >> ex;
    if (!ss.fail())
        exDB[date] = ex;
}

void BitcoinExchange::processInput(const std::string& inputFile)
{
    std::ifstream input(inputFile.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line))
    {
        if (line == "date | value")
            continue;
        handleLine(line);
    }
}

void BitcoinExchange::handleLine(const std::string& line)
{
    size_t sep = line.find(" | ");
    if (sep == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);
    float value;

    if (!isValidValue(valueStr, value))
        return;

    std::map<std::string, double>::iterator it = findClosestDate(date);
    if (it == exDB.end())
    {
        std::cerr << "Error: no valid earlier date in DB." << std::endl;
        return;
    }

    std::cout << date << " => " << value << " = "
              << std::fixed << std::setprecision(2) << value * it->second << std::endl;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
    std::stringstream ss(valueStr);
    ss >> value;
    if (ss.fail() || !ss.eof())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = exDB.lower_bound(date);
    if (it != exDB.end() && it->first == date)
        return it;
    if (it == exDB.begin())
        return exDB.end();
    return --it;
}
