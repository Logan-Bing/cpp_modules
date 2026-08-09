#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main()
{
	Character char_1("Jhon");
	Character char_2("Alice");

	AMateria *mat_1 = new Cure();
	AMateria *mat_2 = new Cure();
	AMateria *mat_3 = new Ice();
	AMateria *mat_4 = new Ice();

	char_2.equip(mat_1);
	char_2.equip(mat_2);
	char_2.equip(mat_3);
	char_2.equip(mat_4);

	char_2.unequip(0);
	char_2.unequip(1);
	char_2.unequip(2);
	char_2.unequip(3);

	char_1.equip(mat_1);
	char_1.equip(mat_2);
	char_1.equip(mat_3);
	char_1.equip(mat_4);

	char_1.unequip(0);
	char_1.unequip(1);
	char_2 = char_1;

	char_2.infos();
	char_1.infos();

	delete mat_1;
	delete mat_2;
	delete mat_3;
	delete mat_4;

	// std::cout << "INIT/COPY ASSIGNEMENT\n";
	// std::cout << "\t"; char_1.equip(mat_1);
	// std::cout << "\t"; char_1.equip(mat_2);
	// std::cout << "\t"; char_1.equip(mat_3);
	// std::cout << "\t"; char_1.equip(mat_4);
	// std::cout << "\t"; char_1.unequip(0);
	// char_2 = char_1;
	//
	// std::cout << "\tBASE INFOS\n";
	// char_1.infos();
	// std::cout << "\tCOPY INFOS\n";
	// char_2.infos();
	// std::cout << "--\n";
	//
	// std::cout << "COPY CONCSTRUCTOR\n";
	// Character char_3(char_2);
	//
	// std::cout << "\tBASE INFOS\n";
	// char_2.infos();
	// std::cout << "\tCOPY INFOS\n";
	// char_3.infos();
	// std::cout << "--\n";
	//
	// std::cout << "MANIPULATE SLOT\n";
	// std::cout << "\t"; char_1.use(0, char_2);
	// std::cout << "\t"; char_1.use(1, char_2);
	// std::cout << "\t"; char_1.use(2, char_2);
	// std::cout << "\t"; char_1.use(3, char_2);
	// std::cout << "\t"; char_1.use(99, char_2);
	// std::cout << "\t"; char_1.use(-1, char_2);
	// std::cout << "--\n";


	return 0;
}
