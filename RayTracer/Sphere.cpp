//
//  Sphere.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

# include "Sphere.h"

Sphere::Sphere(Vector c, double r)
{
	center = c;
	radius = r;
}

double Sphere::getIntersection(Ray ray)
{
	Vector v = ray.origin - center;
	double b = 2 * dot(ray.dir, v);
	double c = dot(v, v) - radius * radius;
	double d = b * b - 4 * c;
	if(d > 0)
	{
		double x1 = (-b - sqrt(d)) / 2;
		double x2 = (-b + sqrt(d)) / 2;
		if(x1 >= 0 && x2 >= 0) return x1;
		if(x1 < 0 && x2 >= 0) return x2;
	}
	return -1;
}

Vector Sphere::getNormal(Vector p)
{
	return (p - center).unit();
}

Material Sphere::getMaterial(Vector p)
{
	return mat;
}

bool Sphere::isLightSource()
{
    return false;
}
