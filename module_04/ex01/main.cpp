#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Array of Animals Test ---\n";

    const int size = 6;
    Animal* Animals[size];

    for (int index = 0; index < size / 2; ++index)
        Animals[index] = new Dog();
    
    for (int index = size / 2; index < size; ++index)
        Animals[index] = new Cat();

    std::cout << "\n--- Deleting Animals ---\n";

    for (int index = 0; index < size; ++index)
        delete Animals[index];

    std::cout << "\n--- Deep Copy Test ---\n";

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I love bones!");

    Dog copiedDog(originalDog);
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
    anotherDog = copiedDog;
    std::cout << "Another Dog's Idea (after assignment): " << anotherDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
