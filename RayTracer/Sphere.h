//
//  Sphere.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Sphere__
#define __RayTracing__Sphere__

# include "Object3D.h"

struct Sphere : Object3D
{
	Vector center;
	double radius;

	Sphere(Vector c, double r);
	double getIntersection(Ray ray);
	Vector getNormal(Vector p);
	Color getColor(Vector p = Vector(0, 0, 0));
    bool isLightSource();
};

#endif /* defined(__RayTracing__Sphere__) */
