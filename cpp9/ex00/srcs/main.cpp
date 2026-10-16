#include "../includes/header.hpp"

int main()
{
	BitcoinExchange b("data.csv");

	b.ParseCsv();
	b.PrintData();

	return 0;
}
