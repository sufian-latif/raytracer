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

Material CheckerBoard::getMaterial(Vector p)
{
    double x = dot(p - pp, u) / size;
    double y = dot(p - pp, v) / size;
    
	if(x * y > 0)
        return (int(x) + int(y)) % 2 ? mat1 : mat2;
    else
        return (int(x) + int(y)) % 2 ? mat2 : mat1;
    
    return mat;
}