#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void): std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}
