//
//  RayTracer.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

# include "RayTracer.h"

# define D2R (acos(0) / 90.0)
# define INF 99999.0
# define sq(x) ((x) * (x))

RayTracer::RayTracer(Vector vp, Vector dir, Vector up, int w, int h, int maxD)
{
	int i;
    
	viewPoint = vp;
	camDir = dir.unit();
	camUp = up.unit();
	width = w;
	height = h;
	maxDepth = maxD;
	camRight = cross(dir, up).unit();
	image = new Color* [height];
	distance = new double* [height];
    
	for(i = 0; i < height; i++)
	{
		image[i] = new Color[width];
		distance[i] = new double[width];
	}
    
	dx = 2 * tan(35 * D2R) / width;
	dy = dx;// * height / width;
	printf ("%lf %lf\n", dx, dy);
}

void RayTracer::createImage(Scene scene)
{
	int i, j;
	Vector origin = viewPoint + camDir - camRight * dx * width / 2 - camUp * dy * height / 2;

	for(i = 0; i < height; i++)
		for(j = 0; j < width; j++)
		{
			Vector pixel = origin + i * dy * camUp + j * dx * camRight;
			Ray ray = Ray(viewPoint, pixel - viewPoint);
            while(!refrInd.empty()) refrInd.pop();
			ColorDistancePair cdp = trace(ray, scene, 0, 1);
            image[i][j] = cdp.first;
            distance[i][j] = cdp.second;
		}
}

ColorDistancePair RayTracer::trace(Ray ray, Scene scene, int depth, double mu)
{
    if(depth > maxDepth)
        return make_pair(Color(0, 0, 0), -1);

    ObjectDistancePair objDist = scene.findClosest(ray);
    Object3D* obj = objDist.first;
    double dist = objDist.second;

    if(obj == NULL)
        return make_pair(scene.background, INF);

    if(obj->isLightSource())
        return make_pair(obj->getColor(), dist);

    Vector hitPoint = ray.origin + dist * ray.dir;
    Vector normal = obj->getNormal(hitPoint);

    
    Color color = Color(0, 0, 0);
    
    // light rays
    
    int i;
    for(i = 0; i < scene.lights.size(); i++)
    {
        Vector dir = (scene.lights[i]->center - hitPoint).unit();
        Ray lightRay = Ray(hitPoint + 0.001 * dir, dir);
        ObjectDistancePair odp = scene.findClosest(lightRay);
        if(odp.first != scene.lights[i]) continue;
        
        // diffuse color
        double cosInc = dot(lightRay.dir, normal);
        double intensity = scene.lights[i]->intensity / sq(odp.second);
        Color diffuse = obj->mat.diffuse * intensity * cosInc * scene.lights[i]->getColor() * obj->getColor(hitPoint);
        color = color + diffuse;

        // specular color
        Vector tmp = (lightRay.dir - 2 * (dot(lightRay.dir, normal)) * normal).unit();
        intensity = pow(dot(ray.dir, tmp), 50) * obj->mat.specular;
        intensity *= scene.lights[i]->intensity / sq(odp.second);
        Color specular = intensity * scene.lights[i]->getColor();
        color = color + specular;
    }
    
	// reflected ray
	Vector dir = ray.dir - 2 * project(ray.dir, normal);
	Ray refl = Ray(hitPoint + 0.001 * dir, dir);
	Color colRefl = trace(refl, scene, depth + 1, mu).first;
    
	// refracted ray
    double nextmu;
    if(angle(ray.dir, normal) < 90 * D2R) // hit from inside
    {
        normal = -normal;
        if(!refrInd.empty())
        {
            nextmu = refrInd.top();
            refrInd.pop();
        }
        else nextmu = 1;
    }
    else
    {
        nextmu = obj->mat.mu;
        refrInd.push(mu);
    }
	double t1 = angle(ray.dir, -normal);
	double t2 = asin(sin(t1) * mu / nextmu);
    if(t2 < 90 * D2R) dir = rotate(ray.dir, cross(ray.dir, normal), t2 - t1);
    else dir = ray.dir - 2 * project(ray.dir, normal);
	Ray refr = Ray(hitPoint + 0.001 * dir, dir);
	Color colRefr = trace(refr, scene, depth + 1, nextmu).first;
    
    color = color + colRefl * obj->mat.reflectance + colRefr * obj->mat.refractance;

    return make_pair(scene.ambient + color, dist);
}

void RayTracer::writeBMP(char* filename)
{
	unsigned int header[14];
	int i, j;
	FILE* fp = fopen(filename, "wb");
    unsigned char pad[3] = {0, 0, 0};
    
	header[0] = 0x4d420000;
	header[1] = 54 + 3 * height * width;
	header[2] = 0;
	header[3] = 54;
	header[4] = 40;
	header[5] = width;
	header[6] = height;
	header[7] = 0x00180001;
	header[8] = 0;
	header[9] = 3 * width * height;
	header[10] = header[11] = header[12] = header[13] = 0;
    
	fwrite((char*)header + 2, 1, 54, fp);
	fflush(fp);
    
	for(i = 0; i < height; i++)
    {
		for(j = 0; j < width; j++)
		{
            unsigned char R = 255 * image[i][j].r;
            unsigned char G = 255 * image[i][j].g;
            unsigned char B = 255 * image[i][j].b;
			fwrite(&B, 1, 1, fp);
			fwrite(&G, 1, 1, fp);
			fwrite(&R, 1, 1, fp);
			//fflush(fp);
		}
        fwrite(pad, width % 4, 1, fp);
    }
    
	fclose(fp);
}

void RayTracer::cleanup()
{
    int i;
    
    for(i = 0; i < height; i++)
    {
        delete [] image[i];
        delete [] distance[i];
    }
    
    delete image;
    delete distance;
}
