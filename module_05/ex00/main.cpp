#include "Bureaucrat.hpp"
int main() {
    try {
        std::cout << "Test 1: Valid Bureaucrat" << std::endl;
        Bureaucrat b1("Alice", 10);
        std::cout << b1 << std::endl;

        std::cout << "\nTest 2: Invalid Bureaucrat - Grade Too High" << std::endl;
        try {
            Bureaucrat b2("Bob", 0);
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 3: Invalid Bureaucrat - Grade Too Low" << std::endl;
        try {
            Bureaucrat b3("Charlie", 151);
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 4: Incrementing Grade" << std::endl;
        Bureaucrat b4("David", 10);
        b4.incrementGrade();
        std::cout << b4 << std::endl;
        
        std::cout << "\nTest 5: Decrementing Grade" << std::endl;
        Bureaucrat b5("Eva", 140);
        b5.decrementGrade();
        std::cout << b5 << std::endl;

        std::cout << "\nTest 6: Incrementing Grade - Grade Too High" << std::endl;
        try {
            Bureaucrat b6("Frank", 1);
            b6.incrementGrade();
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "\nTest 7: Decrementing Grade - Grade Too Low" << std::endl;
        try {
            Bureaucrat b7("Grace", 150);
            b7.decrementGrade();
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "General exception caught: " << e.what() << std::endl;
    }

    return 0;
}

