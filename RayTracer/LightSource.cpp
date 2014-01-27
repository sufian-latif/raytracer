//
//  LightSource.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

# include "LightSource.h"

LightSource::LightSource(Vector c, double r, double in) : Sphere(c, r)
{
    intensity = in;
}

bool LightSource::isLightSource()
{
    return true;
}

/*
double LightSource::getIntersection(Ray ray)
{
	Vector v = ray.origin - position;
	double b = 2 * dot(ray.dir, v);
	double c = dot(v, v) - rad * rad;
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

Vector LightSource::normalAt(Vector p)
{
	return (p - position).unit();
}

Color LightSource::getColor(Vector p)
{
	return color;
}
 
 */
