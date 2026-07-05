#include <ios>
#include <fstream>
#include <iostream>

/*
	std::fstream fs(argv[1], std::ios::in); // Ouverture pour la lecture
	fs_src << "Hello World" // Erreur siliencieuse
*/

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::string replace_file = std::string(argv[1]) + ".replace";
		std::fstream fs_src(argv[1], std::ios::out);
		// File qui existe pas 
		// File qui n'a pas les perm
		std::fstream fs_dest(replace_file.c_str(), std::ios::out);
		fs_src << "hello les gensssssssssss";

		// pas oublier de close les fstream
		return (0);
	}
	std::cout << "invalide nb argument\n";
	return (1);
}
