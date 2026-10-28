#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& rhs);
		~Array();

		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);

		unsigned int size() const;
	
	private:
		T* elements_;
		unsigned int length_;
};

#include "Array.tpp"

#endif
