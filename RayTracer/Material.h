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
	Color ambient, diffuse, specular;
	double reflectance, refractance, mu, shininess;
};

#endif /* defined(__RayTracing__Material__) */
