#include "Character.hpp"
#include "Debug.hpp"
#include "AMateria.hpp"

Character::Character(void): name_(""), slot_(), garbage()
{
	DEBUG_MSG("Character Default Constuctor called\n");
	
}

Character::Character(const std::string& name): name_(name), slot_(), garbage()
{
	DEBUG_MSG("Character Name Constuctor called\n");
}

Character::Character(const Character& other): name_(other.name_)
{
	DEBUG_MSG("Character Copy Constructor called\n");
	for (int i = 0; i < SLOT_SIZE; i++)
		slot_[i] = other.slot_[i]->clone();
}

Character&	Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		name_ = rhs.name_;
		for (int i = 0; i < SLOT_SIZE; i++)
		{
			if (slot_[i])
			{
				delete slot_[i];
				slot_[i] = NULL;
			}

			if (rhs.slot_[i])
				slot_[i] = rhs.slot_[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void)
{
	DEBUG_MSG("\t" << name_ << " get destroyed" << std::endl);

	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot_[i])
			delete slot_[i];
	}


	t_garbage* current = garbage;
	t_garbage* next;

	while (current)
	{
		next = current->next;
		delete current->e;
		delete current;
		current = next;
	}
}

int Character::validIndex(int idx) const
{
	if (idx < 0 || idx >= SLOT_SIZE)
	{
		std::cout << "Invalid index" << std::endl;
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
			std::cout << name_ << " equip a " << m->getType() << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (!validIndex(idx))
		return ;

	std::cout << name_ << " unequip the " << slot_[idx]->getType() << std::endl;
	t_garbage* node = new t_garbage();
	node->e = slot_[idx];
	node->next = garbage;
	garbage = node;
	slot_[idx] = NULL;
}
 
void Character::use(int idx, ICharacter& target)
{
	if (!validIndex(idx))
		return ;

	slot_[idx]->use(target);
}
