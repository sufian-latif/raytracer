//
//  Material.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Material__
#define __RayTracing__Material__

# include "Color.h"

struct Material
{
	Color color;
	double reflectance, refractance, mu, diffuse, specular;
};

#endif /* defined(__RayTracing__Material__) */
