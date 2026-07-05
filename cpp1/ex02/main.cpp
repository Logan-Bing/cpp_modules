#include <iostream>

int main ()
{
	std::string str("HI THIS IS BRAIN");
	
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << 
		"variable Memory Address: " << &str << '\n' <<
		"stringPTR Memory Address: " << stringPTR << '\n' <<
		"stringREF Memory Adress: " << &stringREF << '\n' <<
		"--------------------------\n" <<
		"variable value: " << str << '\n' <<
		"stringPTR value: " << *stringPTR << '\n' <<
		"stringREF value: " << stringREF << '\n';

	return (0);
}
