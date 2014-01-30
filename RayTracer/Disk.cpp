//
//  Disk.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#include "Disk.h"

Disk::Disk(Vector c, Vector normal, double r) : Plane(c, normal)
{
    radius = r;
}

double Disk::getIntersection(Ray ray)
{
    double t = Plane::getIntersection(ray);
    Vector p = ray.origin + t * ray.dir;
    return (p - pp).mag() > radius ? -1 : t;
}
