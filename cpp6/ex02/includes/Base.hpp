#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>

class A;
class B;
class C;

class Base {
 public:
	virtual ~Base();
	static Base* cloneA(void);
	static Base* cloneB(void);
	static Base* cloneC(void);
	Base* generate(void);

	void identify(Base* p);
	void identify(Base& p);
};

#endif
