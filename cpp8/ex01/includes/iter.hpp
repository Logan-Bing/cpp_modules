#ifndef __ITER_HPP
#define __ITER_HPP

#include "iostream"

template <typename T, typename Func>
void iter(T* tab, const size_t length, Func f)
{
	for (size_t i = 0; i < length; i++)
	{
		f(tab[i]);
	}
}

#endif
