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
        throw std::runtime_error("Error: could not open database file.");

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
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(input, line);
    if (line != "date | value")
        throw std::runtime_error("Error: Invalid input file.");
    while (std::getline(input, line))
    {
        try
        {
            handleLine(line);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::handleLine(const std::string& line)
{
    size_t sep = line.find(" | ");
    if (sep == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);
    float value;

    if (!isValidDate(date))
        throw std::runtime_error("Error: bad input => " + date);

    if (!isValidValue(valueStr, value))
        return;

    std::map<std::string, double>::iterator it = findClosestDate(date);
    if (it == exDB.end())
        throw std::runtime_error("Error: no valid earlier date in DB.");

    std::cout << date << " => " << value << " = "
              << std::fixed << std::setprecision(2) << value * it->second << std::endl;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
    std::stringstream ss(valueStr);
    ss >> value;
	if (ss.fail() || !ss.eof())
	{
		std::cout << "Error: bad input" << std::endl;
		return false;
	}
	else if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::stringstream ss;

    ss << date.substr(0, 4);
    ss >> year;
    if (ss.fail())
        return false;

    ss.clear();
    ss.str("");
    ss << date.substr(5, 2);
    ss >> month;
    if (ss.fail())
        return false;

    ss.clear();
    ss.str("");
    ss << date.substr(8, 2);
    ss >> day;
    if (ss.fail()) 
        return false;

    if (month < 1 || month > 12)
        return false;

    int maxDay = 31;
    if (month == 2)
    {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        maxDay = leap ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDay = 30;

    if (day < 1 || day > maxDay)
        return false;

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
