//
//  Object3D.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Object3D__
#define __RayTracing__Object3D__

# include "Ray.h"
# include "Material.h"

struct Object3D
{
	Material mat;
    
	virtual double getIntersection(Ray ray) = 0;
	virtual Vector getNormal(Vector p) = 0;
	virtual Material getMaterial(Vector p = Vector(0, 0, 0)) = 0;
    virtual bool isLightSource() = 0;
};

#endif /* defined(__RayTracing__Object3D__) */
