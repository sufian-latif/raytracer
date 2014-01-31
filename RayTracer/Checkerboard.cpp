//
//  CheckerBoard.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

# include "CheckerBoard.h"

CheckerBoard::CheckerBoard(Vector pp, Vector normal, Vector u, double size) : Plane(pp, normal)
{
    this->u = u.unit();
    this->v = cross(u, normal).unit();
    this->size = size;
}


int clamp(double x)
{
    return x > 0 ? 1 : -1;
}

Color CheckerBoard::getColor(Vector p)
{
	double x = clamp(cos(angle(project(p - pp, u), u))) * project(p - pp, u).mag() / size;
    double y = clamp(cos(angle(project(p - pp, v), v))) * project(p - pp, v).mag() / size;
    
	if(x * y > 0)
		return (int(x) + int(y)) % 2 ? col1 : col2;
	return (int(x) + int(y)) % 2 ? col2 : col1;
}