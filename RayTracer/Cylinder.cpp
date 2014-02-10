//
//  Cylinder.cpp
//  RayTracer
//
//  Created by Sufian Latif on 2/10/14.
//  Copyright (c) 2014 Sufian Latif. All rights reserved.
//

#include "Cylinder.h"

Cylinder::Cylinder(Vector c, Vector a, double h, double r)
{
    center = c;
    axis = a.unit();
    height = h;
    radius = r;
}

double Cylinder::getIntersection(Ray ray)
{
    Vector v1 = ray.dir - axis * dot(ray.dir, axis);
    Vector v2 = ray.origin - center;
    Vector v3 = v2 - dot(v2, axis) * axis;
    
    double a = dot(v1, v1);
    double b = 2 * dot(v1, v3);
    double c = dot(v3, v3) - radius * radius;
    double d = b * b - 4 * a * c;
    
    if (d >= 0)
    {
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        if(x1 >= 0 && x2 >= 0) return x1;
        if(x1 < 0 && x2 >= 0) return x2;
    }
    return -1;
}

Vector Cylinder::getNormal(Vector p)
{
    Vector v = p - center;
    return (v - dot(v, axis) * axis).unit();
}

Material Cylinder::getMaterial(Vector p)
{
    return mat;
}

bool Cylinder::isLightSource()
{
    return false;
}


