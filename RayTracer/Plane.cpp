//
//  Plane.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

# include "Plane.h"

Plane::Plane(Vector pp, Vector normal)
{
	this->pp = pp;
	this->normal = normal;
}

Vector Plane::getNormal(Vector p)
{
	return normal;
}

double Plane::getIntersection(Ray ray)
{
	double t = dot(pp - ray.origin, normal) / dot(ray.dir, normal);
	return t < 0 ? -1 : t;
}

Material Plane::getMaterial(Vector p)
{
    return mat;
}

bool Plane::isLightSource()
{
    return false;
}
