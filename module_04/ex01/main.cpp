#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
    // Basic test for constructor and destructor
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // Should call Dog destructor and Brain destructor
    delete i; // Should call Cat destructor and Brain destructor

    std::cout << "\n--- Array of Animals Test ---\n";

    // Create an array of Animals (half Dogs, half Cats)
    const int size = 6;
    Animal* animals[size];

    for (int index = 0; index < size / 2; ++index)
        animals[index] = new Dog();
    
    for (int index = size / 2; index < size; ++index)
        animals[index] = new Cat();

    std::cout << "\n--- Deleting Animals ---\n";

    for (int index = 0; index < size; ++index)
        delete animals[index]; // Deleting as Animals should call proper destructors

    std::cout << "\n--- Deep Copy Test ---\n";

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I love bones!");

    Dog copiedDog(originalDog); // Deep copy constructor should be called
    std::cout << "Original Dog's Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's Idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    copiedDog.getBrain()->setIdea(0, "I love running!");
    std::cout << "Modified Copied Dog's Idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original Dog's Idea after modification: " << originalDog.getBrain()->getIdea(0) << std::endl;

    if (originalDog.getBrain()->getIdea(0) != copiedDog.getBrain()->getIdea(0))
        std::cout << "Deep copy confirmed!\n";
    else
        std::cout << "Shallow copy detected, fix required!\n";

    std::cout << "\n--- Assignment Operator Test ---\n";

    Dog anotherDog;
    anotherDog = copiedDog; // Deep copy assignment operator should be called
    std::cout << "Another Dog's Idea (after assignment): " << anotherDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
