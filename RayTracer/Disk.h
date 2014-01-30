//
//  Disk.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Disk__
#define __RayTracing__Disk__

# include "Plane.h"

struct Disk : Plane
{
    double radius;
    
    Disk(Vector c, Vector normal, double r);
    double getIntersection(Ray ray);
};

#endif /* defined(__RayTracing__Disk__) */
