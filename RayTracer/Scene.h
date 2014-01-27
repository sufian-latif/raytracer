//
//  Scene.h
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

#ifndef __RayTracing__Scene__
#define __RayTracing__Scene__

# include <vector>
# include <utility>
# include "Object3D.h"
# include "LightSource.h"

using namespace std;

typedef pair <Object3D*, double> ObjectDistancePair;

struct Scene
{
	vector <Object3D*> objects;
	vector <LightSource*> lights;
	Color background;
    Color ambient;
    
	Scene(Color bg, Color amb);
	void addObject(Object3D* obj);
	ObjectDistancePair findClosest(Ray ray);
    void cleanup();
};


#endif /* defined(__RayTracing__Scene__) */
