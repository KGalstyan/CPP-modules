#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    AAnimal* AAnimals[4];

    AAnimals[0] = new Dog();
    AAnimals[1] = new Dog();
    AAnimals[2] = new Cat();
    AAnimals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << "AAnimal " << i + 1 << " is a " << AAnimals[i]->getType() << " and it says: ";
        AAnimals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete AAnimals[i];
    }

    return 0;
}

