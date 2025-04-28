#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
    public:
        Span();
        Span(const unsigned int smth);
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        ~Span();

        void addNumber(int);
        int shortestSpan() const;
        int longestSpan() const;
        void fill();

    private:
        unsigned int N;
        std::vector<int> vec;
}

#endif