#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const std::string& str)
{
    (void)str;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
    if(this != &obj)
    {
        *this = obj;
    }
    return(*this);
}

ScalarConverter::~ScalarConverter()
{
}

/***************************** Check and Convert functions *****************************/

bool ScalarConverter::check_number(const std::string& str)
{
    if (str.empty())
        return false;

    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;

    if (i >= str.size())
        return false;

    bool haveDot = false, haveDigit = false;
    size_t len = str.length();

    bool haveF = (str[len - 1] == 'f');
    if (haveF)
        --len;

    while (i < len)
    {
        if (std::isdigit(str[i]))
            haveDigit = true;
        else if (str[i] == '.' && !haveDot)
            haveDot = true;
        else
            return false;
        i++;
    }

    return haveDigit;
}

void ScalarConverter::convert(const std::string& str)
{
    if(str == "nan" || str == "nanf")
        PrintNan();
    else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        PrintInf(str);
    else if(check_number(str))
    {
        PrintChar(str);
        PrintInt(str);
        PrintFloat(str);
        PrintDouble(str);
    }
    else
        PrintImpossible();
}


/***************************** Print functions *****************************/

void ScalarConverter::PrintInt(const std::string& str)
{
    std::cout << "int: " << std::atoi(str.c_str()) << std::endl;
}

void ScalarConverter::PrintChar(const std::string& str)
{
    char c = static_cast<char>(std::atoi(str.c_str()));
    std::cout << "char: ";
	if (c < 0)
		std::cout << "impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
}

void ScalarConverter::PrintDouble(const std::string& str)
{
    double res = std::strtod(str.c_str(), NULL);
	std::cout << "Double: " << res;
	if (res == static_cast<int>(res))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::PrintFloat(const std::string& str)
{
    float res = std::strtof(str.c_str(), NULL);
	std::cout << "Float: " << res;
	if (res == static_cast<int>(res))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void ScalarConverter::PrintImpossible()
{
    std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConverter::PrintNan()
{
    std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}

void ScalarConverter::PrintInf(const std::string& str)
{
    std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << (str[0] == '-' ? "-" : "+") << "inff" << std::endl;
	std::cout << "double: " << (str[0] == '-' ? "-" : "+") << "inf" << std::endl;
    (void)str;
}
