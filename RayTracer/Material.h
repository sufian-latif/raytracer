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
# include <map>
# include <string>

using namespace std;

struct Material
{
	Color ambient, diffuse, specular;
	double reflectance, refractance, mu, shininess;
};

extern map <string, Material> materials;
void loadMaterials(char *file);

#endif /* defined(__RayTracing__Material__) */
