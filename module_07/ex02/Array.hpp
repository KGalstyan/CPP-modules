#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int _n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        ~Array();

        unsigned int size() const;
        T &operator[](const unsigned int);
    private:
        T *arr;
        unsigned int n;
};

#include "Array.tpp"

#endif