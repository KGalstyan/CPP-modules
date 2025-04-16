#include "Base.hpp"

Base * generate(void)
{
    int case_num = (std::rand() % 3);
    switch(case_num)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "is A" << std::endl;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "is B" << std::endl;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "is C" << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown type" << std::endl;
    }
}

int main()
{
    Base* obj = generate();

    std::cout << "Identify using pointer: ";
    identify(obj);

    std::cout << "Identify using reference: ";
    identify(*obj);

    delete obj;
    return 0;
}