//
//  Scene.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

# include "Scene.h"

Scene::Scene(Color bg, Color amb)
{
	background = bg;
    ambient = amb;
	objects.clear();
    lights.clear();
}

void Scene::addObject(Object3D* obj)
{
    if(obj->isLightSource())
        lights.push_back((LightSource*)obj);
	objects.push_back(obj);
}

ObjectDistancePair Scene::findClosest(Ray ray)
{
	int i;
	double dist = 99999.0;
	Object3D* ob = NULL;

	for(i = 0; i < objects.size(); i++)
	{
		double d = objects[i]->getIntersection(ray);
		if(d < 0) continue;
		if(d < dist)
		{
			dist = d;
			ob = objects[i];
		}
	}

	return make_pair(ob, dist);
}

void Scene::cleanup()
{
    lights.clear();
    objects.clear();
}