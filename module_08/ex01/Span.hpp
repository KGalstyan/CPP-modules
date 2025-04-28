#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
    public:
        Span();
        Span(const unsigned int value);
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        ~Span();
        
        void addNumber(int value);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename T>
        void fill(T begin, T end);

    private:
        unsigned int N;
        std::vector<int> vec;
};

#endif