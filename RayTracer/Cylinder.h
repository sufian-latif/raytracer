//
//  Cylinder.h
//  RayTracer
//
//  Created by Sufian Latif on 2/10/14.
//  Copyright (c) 2014 Sufian Latif. All rights reserved.
//

#ifndef __RayTracer__Cylinder__
#define __RayTracer__Cylinder__

# include "Object3D.h"

struct Cylinder : Object3D
{
    Vector center, axis;
    double height, radius;
    
    Cylinder(Vector c, Vector a, double h, double r);
    double getIntersection(Ray ray);
    Vector getNormal(Vector p);
    Material getMaterial(Vector p);
    bool isLightSource();
};

#endif /* defined(__RayTracer__Cylinder__) */
