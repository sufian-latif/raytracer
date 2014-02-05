//
//  Quad.cpp
//  RayTracer
//
//  Created by Sufian Latif on 2/4/14.
//  Copyright (c) 2014 Sufian Latif. All rights reserved.
//

#include "Quad.h"

Quad::Quad(Vector pp, Vector normal, Vector side1, Vector side2) : Plane(2 * pp, normal)
{
    this->side1 = side1;
    this->side2 = side2;
}

double Quad::getIntersection(Ray ray)
{
    double t = Plane::getIntersection(ray);
    Vector p = ray.origin + t * ray.dir;
    double s1 = project((p - pp), side1).mag();
    double s2 = project((p - pp), side2).mag();
    return s1 >= 0 && s1 <= side1.mag() && s2 >= 0 && s2 <= side2.mag() ? t : -1;
}