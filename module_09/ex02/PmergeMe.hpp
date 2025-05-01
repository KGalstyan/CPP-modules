#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <sstream>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe &operator=(const PmergeMe& obj);
        ~PmergeMe();

        void fill(int argc, char**argv);
        
        template <typename T>
        void sort(T& c);
        void manage();
        void print();
    public:
        std::vector<int> vec;
        std::deque<int> deq;
};

#endif