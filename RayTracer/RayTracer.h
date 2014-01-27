//
//  RayTracer.h
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

#ifndef __RayTracing__RayTracer__
#define __RayTracing__RayTracer__

# include "Vector.h"
# include "Color.h"
# include "Scene.h"
# include <utility>

typedef pair<Color, double> ColorDistancePair;

struct RayTracer
{
	Color **image;
	double **distance;
	int width, height, maxDepth;
	Vector viewPoint, camDir, camUp, camRight;
	double fov, dx, dy, dz, aspect, right, down;

	RayTracer(Vector vp, Vector dir, Vector up, int w, int h, int maxD);
	ColorDistancePair trace(Ray ray, Scene scene, int depth);
	void createImage(Scene scene);
	void writeBMP(char* filename);
    void cleanup();
};

#endif /* defined(__RayTracing__RayTracer__) */
