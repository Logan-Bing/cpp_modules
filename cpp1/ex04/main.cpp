#include <iostream>
#include "FileReplacer.hpp"

/*
	std::fstream fs(argv[1], std::ios::in); // Ouverture pour la lecture
	fs_src << "Hello World" // Erreur siliencieuse
*/

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		FileReplacer job(argv[1], argv[2], argv[3]);
		job.run();
		return (0);
	}
	std::cout << "invalide nb argument\n";
	return (1);
}
