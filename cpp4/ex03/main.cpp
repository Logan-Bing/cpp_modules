#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	Character char_1("Jhon");
	Character char_2("Alice");

	AMateria *mat_1 = new Cure();
	AMateria *mat_2 = new Cure();
	AMateria *mat_3 = new Cure();


	std::cout << "COPY\n";
	std::cout << "\tBASE: "; char_1.equip(mat_1);
	std::cout << "\tBASE: "; char_1.equip(mat_2);
	std::cout << "\tCOPY: "; char_2.equip(mat_3);
	char_2 = char_1;
	std::cout << "\tCOPY name: "; std::cout << char_2.getName() << std::endl;
	std::cout << "\tCOPY slots[0]: "; char_2.use(0, char_1);
	std::cout << "\tCOPY slots[1]: "; char_2.use(1, char_1);
	std::cout << "\tCOPY slots[1]: "; char_2.unequip(1);
	std::cout << "\tCOPY slots[0]: "; char_2.unequip(0);
	std::cout << "\tCOPY slots[0]: "; char_2.unequip(1);
	std::cout << "\tCOPY slots[0]: "; char_2.unequip(1);
	std::cout << "\tCOPY slots[1]: "; char_2.use(1, char_1);
	std::cout << "\tBASE slots[0]: "; char_1.use(1, char_2);
	std::cout << "--\n";
	//
	// std::cout << "INVALID INDEX TEST\n";
	// std::cout << "\t"; char_1.use(-1, char_2);
	// std::cout << "\t"; char_1.use(1, char_2);
	// std::cout << "\t"; char_1.unequip(2);
	// std::cout << "\t"; char_1.unequip(-2);
	// std::cout << "--\n";
	//
	// std::cout << "MANIPULATE SLOT\n";
	// std::cout << "\t"; char_1.equip(mat_1);
	// std::cout << "\t"; char_1.equip(mat_2);
	// std::cout << "\t"; char_1.use(0, char_2);
	// std::cout << "\t"; char_1.use(1, char_2);
	// std::cout << "\t"; char_1.unequip(0);
	// std::cout << "\t"; char_1.unequip(1);
	// std::cout << "--\n";

	return 0;
}
