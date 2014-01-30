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

struct LightSource : Sphere
{
	double intensity;
    
	LightSource(Vector c, double r, double in);
    bool isLightSource();
};

#endif /* defined(__RayTracing__LightSource__) */
