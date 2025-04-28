#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> 

template <typename T>
typename T::iterator	easyfind(T& cont, int value)
{
	 return (std::find(cont.begin(), cont.end(), value));
}

#endif