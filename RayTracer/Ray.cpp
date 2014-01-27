//
//  Ray.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#include "Ray.h"

Ray::Ray() {}

Ray::Ray(Vector origin, Vector dir, double mu)
{
	this->origin = origin;
	this->dir = dir.unit();
	this->mu = mu;
}
