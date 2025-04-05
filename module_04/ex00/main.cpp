#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const AAnimal* meta = new AAnimal();
//     const AAnimal* j = new Dog();
//     const AAnimal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     // ...
//     delete i;
//     delete j;
//     return 0;
// }

int AniMain()
{
    const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    const WrongAAnimal* wrongMeta = new WrongAAnimal();
    const WrongAAnimal* wrongCat = new WrongCat();

    std::cout << "Testing WrongAAnimal and WrongCat:" << std::endl;
    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}

int main()
{
    AniMain();
    return 0;
}