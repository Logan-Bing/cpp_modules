#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): materias_()
{
	DEBUG_MSG("MateriaSource Default Constuctor called\n");
}

MateriaSource::MateriaSource(const MateriaSource& other): materias_()
{
	DEBUG_MSG("MateriaSource Copy Constuctor called\n");
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (other.materias_[i])
			materias_[i] = other.materias_[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < SLOT_SIZE; i++)
		{
			if (materias_[i])
			{
				delete materias_[i];
				materias_[i] = NULL;
			}

			if (rhs.materias_[i])
				materias_[i] = rhs.materias_[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	DEBUG_MSG("MateriaSource Destructor called\n");

	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (materias_[i])
		{
			delete materias_[i];
			materias_[i] = NULL;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (materias_[i] && materias_[i]->getType() == type)
		{
			return materias_[i]->clone();
		}
	}
	return NULL;
}


void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (!materias_[i])
		{
			materias_[i] = m;
			return;
		}
	}
}

void	MateriaSource::infos()
{
	std::cout << "\tMaterias = {" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (materias_[i])
		{
			std::cout << "\t\t[" << i << "] : " << materias_[i]->getType() << " | " << materias_[i];
			std::cout << std::endl;
		}
		else
		{
			std::cout << "\t\t[" << i << "] : " << "NULL";
			std::cout << std::endl;
		}
	}
	std::cout << "\t}" << std::endl;
	std::cout << std::endl;
}
