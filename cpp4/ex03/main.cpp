#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	Character char_1("Jhon");
	Character char_2("Alice");

	AMateria *mat_1 = new Cure();
	AMateria *mat_2 = new Cure();
	AMateria *mat_3 = new Ice();
	AMateria *mat_4 = new Ice();


	std::cout << "INIT/COPY ASSIGNEMENT Character" << std::endl;
	char_1.equip(mat_1);
	char_1.equip(mat_2);
	char_1.equip(mat_3);
	char_1.equip(mat_4);
	char_1.unequip(0);
	char_2 = char_1;

	std::cout << "\tBASE INFOS\n";
	char_1.infos();
	std::cout << "\tCOPY INFOS\n";
	char_2.infos();
	std::cout << "--\n";

	std::cout << "COPY CONCSTRUCTOR\n";
	Character char_3(char_2);

	std::cout << "\tBASE INFOS\n";
	char_2.infos();
	std::cout << "\tCOPY INFOS\n";
	char_3.infos();
	std::cout << "--\n";

	std::cout << "MANIPULATE SLOT\n";
	std::cout << "\t"; char_1.use(0, char_2);
	std::cout << "\t"; char_1.use(1, char_2);
	std::cout << "\t"; char_1.use(2, char_2);
	std::cout << "\t"; char_1.use(3, char_2);
	std::cout << "\t"; char_1.use(99, char_2);
	std::cout << "\t"; char_1.use(-1, char_2);
	std::cout << "\t"; char_1.unequip(99);
	std::cout << "\t"; char_1.unequip(-1);
	std::cout << "--\n";

	std::cout << "INIT/COPY ASSIGNEMENT MateriaSource" << std::endl;
	MateriaSource matS_1;
	MateriaSource matS_2;

	matS_1.learnMateria(new Ice());
	matS_1.learnMateria(new Cure());

	matS_2 = matS_1;

	std::cout << "\tBASE INFOS\n";
	matS_1.infos();
	std::cout << "\tCOPY INFOS\n";
	matS_2.infos();

	std::cout << "COPY CONCSTRUCTOR MateriaSource\n";
	MateriaSource matS_3(matS_2);
	matS_3.infos();

	std::cout << "42 TEST\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << "\t"; me->use(0, *bob);
	std::cout << "\t"; me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << "--\n";
	return 0;
}
