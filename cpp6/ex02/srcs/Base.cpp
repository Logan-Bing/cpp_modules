#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../utils/Debug.hpp"
#include <exception>

Base::~Base(void)
{
	DEBUG_MSG("Base Destructor called\n");
}

Base* Base::cloneA(void)
{
	return new A();
}

Base* Base::cloneB(void)
{
	return new B();
}

Base* Base::cloneC(void)
{
	return new C();
}

Base* Base::generate(void)
{
	Base* (*actions[])(void) = {cloneA, cloneB, cloneC};

	return actions[std::rand() % 3]();
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception& e){};

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception& e){};

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception& e){};
}
