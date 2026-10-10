#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <ostream>
#include <vector>

typedef std::vector<int> ints_v;

class Span {
 public:
  // Constuctor/Destructor
  Span(void);
  Span(unsigned int N);
  Span(const Span& other);
  Span& operator=(const Span& rhs);
  ~Span(void);

  void	addNumber(int n);

  template <typename T>
  void	addNumbers(T nums)
  {
	for (typename T::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		addNumber(*it);
	}
  }

  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;

  void	printElements() const;

 private:
  ints_v elements_;
  unsigned int max_size_;
};

#endif
