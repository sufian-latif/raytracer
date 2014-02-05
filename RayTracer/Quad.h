//
//  Quad.h
//  RayTracer
//
//  Created by Sufian Latif on 2/4/14.
//  Copyright (c) 2014 Sufian Latif. All rights reserved.
//

#ifndef __RayTracer__Quad__
#define __RayTracer__Quad__

# include "Plane.h"

struct Quad : Plane
{
    Vector side1, side2;
    
    Quad(Vector pp, Vector normal, Vector side1, Vector side2);
    double getIntersection(Ray ray);
};

#endif /* defined(__RayTracer__Quad__) */
