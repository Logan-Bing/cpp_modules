#include <exception>
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>


class Base {
	public:
		Base() { std::cout << "Base Default constructor called\n"; }
		
		std::string name_;
};

class Derived: virtual public Base
{
	public:
		Derived() { std::cout << "Derived Default constructor called\n"; }
};

class Derived2: virtual public Base
{
	public:
		Derived2() { std::cout << "Derived2 Default constructor called\n"; }
};

class Foo: public Derived, public Derived2
{
	public:
		Foo() {std::cout << "Foo default constructor\n";}
};

int main()
{
	Foo f;

	std::cout << sizeof(f);
	return (0);
}
