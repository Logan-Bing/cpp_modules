#include "../includes/whatever.hpp"
#include <cassert>
#include <iostream>
#include <string>

class Value
{
private:
	Value();
	int value_;
	int id_;

public:
	Value(int value, int id): value_(value), id_(id) {}
	Value(const Value& other): value_(other.value_), id_(other.id_) {}
	Value& operator=(const Value& other)
	{
		value_ = other.value_;
		id_ = other.id_;
		return *this;
	}
	~Value() {}
	int id() const { return id_; }
	bool operator<(const Value& other) const { return value_ < other.value_; }
	bool operator>(const Value& other) const { return value_ > other.value_; }
	bool operator<=(const Value& other) const { return value_ <= other.value_; }
	bool operator>=(const Value& other) const { return value_ >= other.value_; }
	bool operator==(const Value& other) const { return value_ == other.value_; }
	bool operator!=(const Value& other) const { return value_ != other.value_; }
};

int main()
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	assert(a == 3 && b == 2);
	assert(::min(a, b) == 2 && ::max(a, b) == 3);
	::swap(a, a);
	assert(a == 3);

	std::string first = "chaine1";
	std::string second = "chaine2";
	::swap(first, second);
	assert(first == "chaine2" && second == "chaine1");
	assert(::min(first, second) == "chaine1");
	assert(::max(first, second) == "chaine2");

	Value x(5, 1);
	Value y(5, 2);
	assert(::min(x, y).id() == 2);
	assert(::max(x, y).id() == 2);
	::swap(x, y);
	assert(x.id() == 2 && y.id() == 1);
	std::cout << "All tests passed" << std::endl;
}
