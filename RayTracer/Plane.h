//
//  Plane.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Plane__
#define __RayTracing__Plane__

# include "Object3D.h"

struct Plane : Object3D
{
	Vector normal, pp;

    Plane(Vector pp, Vector normal);
	double getIntersection(Ray ray);
	Vector getNormal(Vector p);
	Material getMaterial(Vector p);
    bool isLightSource();
    
};

#endif /* defined(__RayTracing__Plane__) */
