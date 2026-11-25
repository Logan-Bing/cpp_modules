#include "../includes/header.hpp"
#include <climits>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define ROWS 5
#define COLS 5
#define BIG_SIZE 10000

void	test(const Span& s)
{
	std::cout << "nums: ";
	s.printElements();
	std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << s.longestSpan() << std::endl;
}

int main()
{
	Span s(0);

	try
	{
		s.addNumber(10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	int seed[ROWS][COLS] = 
	{
		{INT_MIN, 0, 1, 2,INT_MAX},
		{1, 100, 300, 200,2},
		{6, 3, 17, 9, 11},
		{-10, -5, -99, -9, -0},
		{0, 0, 0, 0, 0}
	};

	for (int i = 0; i < ROWS; i++)
	{
		ints_v v(seed[i], seed[i] + COLS);
		Span s(COLS);
		s.addNumbers(v.begin(), v.end());
		test(s);
		std::cout << "-----" << std::endl;
	}

	// Test avec 10 000 éléments
	{
		ints_v v;
		for (int i = 0; i < BIG_SIZE; i++)
			v.push_back(i * 100);
		v[4243] = 424201; // 424200 existe déjà à l'index 4242
		Span big(BIG_SIZE);
		big.addNumbers(v.begin(), v.end());
		test(big);
		std::cout << "expected -> shortest: 1, longest: 999900" << std::endl;
		std::cout << "-----" << std::endl;
	}

	return 0;
}
