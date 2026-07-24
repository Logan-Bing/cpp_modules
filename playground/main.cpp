#include <exception>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>


class Base {
	public:
		Base(std::string name): name_(name + "suffix"){}
		std::string name_;
};

class Derived: public Base {
	public:
		Derived(std::string name): Base(name){}
		void attack(void)
		{
			std::cout << this->name_;
		}
};

class MoreDerived: public Derived {
	public:
		MoreDerived(std::string name): Derived(name), name_(name){}
		std::string name_;
};

int main()
{
	Derived d("logan");

	d.attack();
	return (0);
}
