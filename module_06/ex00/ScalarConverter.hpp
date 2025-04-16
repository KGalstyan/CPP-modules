#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
    public:
        static void convert(const std::string& str);
    private:
        ScalarConverter();
        ScalarConverter(const std::string& str);
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter &operator=(const ScalarConverter &obj);
        ~ScalarConverter();

        static void PrintInt(const std::string& str);
        static void PrintChar(const std::string& str);
        static void PrintDouble(const std::string& str);
        static void PrintFloat(const std::string& str);
        static void PrintImpossible();
        static void PrintNan();
        static void PrintInf(const std::string& str);

        static bool check_number(const std::string& str);
};

#endif