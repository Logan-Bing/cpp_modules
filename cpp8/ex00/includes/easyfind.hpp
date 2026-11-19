#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T& elements, int target)
{
	typename T::const_iterator e = std::find(elements.begin(), elements.end(), target);
	if (e == elements.end())
		throw std::out_of_range("out of range");
	return e;
}

#endif
