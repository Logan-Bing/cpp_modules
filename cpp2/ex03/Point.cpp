#include "Point.hpp"

int Point::getX(void) const
{
	return this->x_.toInt();
}

int Point::getY(void) const
{
	return this->y_.toInt();
}

Point::Point(void){}

Point::Point(const float x, const float y): x_(x), y_(y){}

Point::Point(Point& rhs): x_(rhs.x_), y_(rhs.y_){}

Point& Point::operator=(Point& rhs)
{
	(void)rhs;
	return *this;
}

Point::~Point(){}
