//
//  LightSource.h
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

#ifndef __RayTracing__LightSource__
#define __RayTracing__LightSource__

# include "Sphere.h"
# include "Vector.h"
# include "Color.h"

struct LightSource : Sphere
{
	double intensity;
    
	LightSource(Vector c, double r, double i);
    bool isLightSource();
};

#endif /* defined(__RayTracing__LightSource__) */
