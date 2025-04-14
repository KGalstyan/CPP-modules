#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form taxForm("TaxForm", 50, 30);
        std::cout << taxForm << std::endl;

        Bureaucrat alice("Alice", 45);
        std::cout << alice << std::endl;

        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm);
        
        Bureaucrat bob("Bob", 60);
        std::cout << bob << std::endl;

        Form permit("WorkPermit", 40, 20);
        std::cout << permit << std::endl;

        bob.signForm(permit);

        try
        {
            Form badForm1("BadForm1", 0, 50);
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        try
        {
            Form badForm2("BadForm2", 151, 50);
        }
        catch (const std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        try
        {
            Form badForm3("BadForm3", 50, 152);
        }
        catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Fatal error: " << e.what() << std::endl;
    }

    return 0;
}
