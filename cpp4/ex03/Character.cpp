#include "Character.hpp"
#include "Debug.hpp"
#include "AMateria.hpp"

Character::Character(void): name_(""), slot_(), stuff_()
{
	DEBUG_MSG("Character Default Constuctor called\n");
}

Character::Character(const std::string& name): name_(name), slot_(), stuff_()
{
	DEBUG_MSG("Character Name Constuctor called\n");
}

Character::Character(const Character& other): name_(other.name_), slot_(), stuff_()
{
	DEBUG_MSG("Character Copy Constructor called\n");
	copySlot(other);
	copyStuff(other);
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		name_ = rhs.name_;
		clearSlot();
		copySlot(rhs);

		clearStuff();
		copyStuff(rhs);
	}
	return *this;
}

Character::~Character(void)
{
	DEBUG_MSG("\t" << name_ << " get destroyed" << std::endl);

	clearSlot();
	clearStuff();
}

int Character::validIndex(int idx) const
{
	if (idx < 0 || idx >= SLOT_SIZE)
	{
		std::cout << "Invalid index: " << idx << std::endl;
		return 0;
	}

	if (!slot_[idx])
	{
		std::cout <<  "The slot " << idx << " is empty" << std::endl;
		return 0;
	}

	return 1;
}

const std::string& Character::getName() const
{
	return name_;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (!slot_[i])
		{
			slot_[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (!validIndex(idx))
		return ;

	t_stuff* node = new t_stuff();
	node->e = slot_[idx];
	node->next = stuff_;
	stuff_ = node;
	slot_[idx] = NULL;
}
 
void Character::use(int idx, ICharacter& target)
{
	if (!validIndex(idx))
		return ;

	slot_[idx]->use(target);
}

void	Character::infos()
{
	std::cout << "\tName = " << name_ << std::endl;
	std::cout << "\tSlot = {" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot_[i])
		{
			std::cout << "\t\t[" << i << "] : " << slot_[i]->getType() << " | " << slot_[i];
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

	std::cout << "\tStuff = {" << std::endl;
	t_stuff* current = stuff_;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (current)
		{
			int i = 0;
			std::cout << "\t\t[" << i << "] : " << current->e->getType() << " | " << current->e;
			std::cout << std::endl;
			i++;
			current = current->next;
		}
		else
		{
			std::cout << "\t\t[" << i << "] : " << "NULL";
			std::cout << std::endl;
		}
	}
	std::cout << "\t}" << std::endl;
}

void	Character::copySlot(const Character& other)
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (other.slot_[i])
			slot_[i] = other.slot_[i]->clone();
	}
}

void	Character::copyStuff(const Character& other)
{
	t_stuff* current = other.stuff_;
	while (current)
	{
		t_stuff* node = new t_stuff();
		node->e = current->e->clone();
		node->next = stuff_;
		stuff_ = node;
		current = current->next;
	}
}

void	Character::clearSlot()
{
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot_[i])
		{
			delete slot_[i];
			slot_[i] = NULL;
		}
	}
}

void	Character::clearStuff()
{
	t_stuff* current = stuff_;
	t_stuff* next;

	while (current)
	{
		next = current->next;
		delete current->e;
		delete current;
		current = next;
	}
	stuff_ = NULL;
}
