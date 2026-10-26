#include "../includes/header.hpp"

#define DATA_FILENAME "data.csv"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		BitcoinExchange b(DATA_FILENAME, argv[1]);
		b.handleDataFile();
		b.handleInputFile();
		return 0;
	}

	std::cout << "Error: could not open file." << std::endl;
	return 1;
}
