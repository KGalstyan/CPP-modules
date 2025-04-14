#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== FORM CREATION TESTS ===" << std::endl;
    try {
        Form form1(50, 25, "ValidForm", false);
        std::cout << form1 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error during valid form creation: " << e.what() << std::endl;
    }

    try {
        Form badForm1(0, 25, "SignGradeTooHigh", false);
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try {
        Form badForm2(151, 25, "SignGradeTooLow", false);
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try {
        Form badForm3(25, 0, "ExecGradeTooHigh", false);
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    try {
        Form badForm4(25, 151, "ExecGradeTooLow", false);
    } catch (const std::exception &e) {
        std::cerr << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== SIGNING TESTS ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);
        Form contract(50, 25, "ContractForm", false);
        std::cout << alice << std::endl;
        std::cout << contract << std::endl;

        alice.signForm(contract);  // should succeed
        std::cout << contract << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Signing test failed: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 100);
        Form secret(50, 25, "TopSecretForm", false);
        std::cout << bob << std::endl;
        std::cout << secret << std::endl;

        bob.signForm(secret);  // should fail
        std::cout << secret << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Signing test failed: " << e.what() << std::endl;
    }

    std::cout << "\n=== ALREADY SIGNED FORM ===" << std::endl;
    try {
        Bureaucrat chad("Chad", 1);
        Form elite(5, 5, "EliteForm", true);  // already signed
        std::cout << elite << std::endl;
        chad.signForm(elite);  // should print already signed or no-op (based on your logic)
        std::cout << elite << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Already signed test failed: " << e.what() << std::endl;
    }

    return 0;
}
