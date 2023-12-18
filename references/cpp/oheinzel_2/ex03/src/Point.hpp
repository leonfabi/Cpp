#ifndef POINT_H
# define POINT_H
# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(const Point &rhs);
		Point(float const newX, float const newY);
		~Point(void);
		Point& operator=(const Point &rhs);
		Fixed const getX(void) const;
		Fixed const getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
