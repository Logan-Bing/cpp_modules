#include "../includes/Array.hpp"
#include "iostream"

template <typename T>
Array<T>::Array(): elements_(NULL), length_(0) {}

template <typename T>
Array<T>::Array(unsigned int n): elements_(new T[n]), length_(n) {}

template <typename T>
Array<T>::Array(const Array& other): length_(other.length_)
{
	elements_ = new T[length_];
	for (size_t i = 0; i < length_; i++)
		elements_[i] = other.elements_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != rhs)
	{
		delete[] elements_;
		for (size_t i = 0; i < length_; i++)
			elements_[i] = rhs.elements_[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] elements_;
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index > length_)
		throw std::out_of_range("Out of ranges");
	return elements_[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index > length_)
		throw std::out_of_range("Out of ranges");
	return elements_[index];
}

template <typename T>
unsigned int Array<T>::size()
{
	return length_;
}
