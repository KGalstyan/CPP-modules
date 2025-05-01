#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    this -> deq = obj.deq;
    this -> vec = obj.vec;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        this -> deq = obj.deq;
        this -> vec = obj.vec;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}