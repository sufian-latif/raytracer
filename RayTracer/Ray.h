//
//  Ray.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Ray__
#define __RayTracing__Ray__

# include "Vector.h"

struct Ray
{
	Vector origin, dir;
	double mu;
    
	Ray();
	Ray(Vector origin, Vector dir, double mu = 1.0);
};

#endif /* defined(__RayTracing__Ray__) */
