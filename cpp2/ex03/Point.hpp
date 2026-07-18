#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
 public:
	// Factory functions

	/* @brief Get x and y */
	int	getX(void) const;
	int	getY(void) const;

	// Constructor/ Destructor
	Point(void);
	Point(const float x, const float y);
	Point(Point& other);
	Point& operator=(Point& rhs);
	~Point(void);

 private:
	 const Fixed x_;
	 const Fixed y_;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
