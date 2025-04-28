#include "Span.hpp"

template <typename T>
void Span::fill(T begin, T end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

Span::Span() : N(0)
{
}

Span::Span(const unsigned int value) : N(value)
{
}

Span::Span(const Span& obj) : N(obj.N) , vec(obj.vec)
{
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
	{
		N = obj.N;
		vec = obj.vec;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
    if (this->vec.size() == this->N)
        throw std::length_error("Maximum size exceeded !");
    vec.push_back(value);
}

int Span::shortestSpan() const
{
    if (vec.size() < 2)
    throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = vec;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = INT_MAX;
    for (std::size_t i = 1; i < sorted.size(); ++i)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minDiff)
        minDiff = diff;
    }
    return minDiff;
}

int Span::longestSpan() const
{
    if (vec.size() < 2)
        throw std::logic_error("Not enough numbers");
    return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}
