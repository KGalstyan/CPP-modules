#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
	    MutantStack();
	    MutantStack(const MutantStack<T> &obj);
	    MutantStack &operator=(const MutantStack<T> &obj);
	    ~MutantStack();

	    typedef typename std::stack<T>::container_type::iterator iterator;
	    iterator begin();
	    iterator end();

	    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	    const_iterator cbegin();
	    const_iterator cend();

	    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();

	    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	    const_reverse_iterator crbegin();
	    const_reverse_iterator crend();
};

#include "MutantStack.tpp"

#endif
