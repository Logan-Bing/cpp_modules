#include <exception>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>

class Person
{
	public:
		void direAge();
		void direName();
		void setAge(int n);
		void setName(std::string name);

	private:
		int age_;
		std::string name_;
};

void Person::direAge()
{
	std::cout << age_ << std::endl;
};

void Person::direName()
{
	std::cout << name_ << std::endl;
};

void Person::setAge(int n)
{
	age_ = n;
}

void Person::setName(std::string name)
{
	name_ = name;
}


int main()
{
	Person p1;
	Person p2;

	p1.setAge(10);
	p1.direAge();
	p2.setAge(20);
	p2.direAge();

	p1.setName("logan");
	p1.direName();
	p1.setName("Hippolyte");
	p1.direName();
}
