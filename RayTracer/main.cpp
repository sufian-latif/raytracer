//
//  main.cpp
//  RayTracer
//
//  Created by Sufian Latif on 1/26/14.
//  Copyright (c) 2014 Sufian Latif. All rights reserved.
//

# include "RayTracer.h"
# include "Object3D.h"
# include "Vector.h"
# include "Sphere.h"
# include "Plane.h"
# include "LightSource.h"

int main()
{
    Vector camPos = Vector(0, 0, 10);
	Vector v;
	RayTracer rt = RayTracer(camPos, -K, J, 800, 600, 8);
	Scene scn1 = Scene(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0));
    
	v = Vector(0, 0, 0);
    
    LightSource *ls1 = new LightSource(Vector(0, 2, 6), 0.05, 10);
    ls1->mat.color = Color(1, 1, 1);
    scn1.addObject(ls1);
    
//    LightSource *ls2 = new LightSource(Vector(-2, 3, 7), 0.05, 10);
//    ls2->mat.color = Color(1, 1, 1);
//    scn1.addObject(ls2);
    
    Plane *p1 = new Plane(Vector(-1, -2, -1), J);
    p1->mat.color = Color(1, 1, 1);
    p1->mat.diffuse = 1;
    p1->mat.reflectance = 0.5;
    scn1.addObject(p1);
    
    Plane *p2 = new Plane(Vector(-1, -1, -1), I + K);
    p2->mat.color = Color(0, 1, 0);
    p2->mat.diffuse = 1;
    p2->mat.reflectance = 0.5;
    scn1.addObject(p2);

    Plane *p3 = new Plane(Vector(1, -1, -1), -I + K);
    p3->mat.color = Color(0, 0, 1);
    p3->mat.diffuse = 1;
    p3->mat.reflectance = 0.5;
    scn1.addObject(p3);
    
    Sphere *s1 = new Sphere(Vector(2, -1, 2), 1);
    s1->mat.color = Color(1, 0, 0);
    s1->mat.diffuse = 0.9;
    s1->mat.specular = 0.9;
    s1->mat.reflectance = 1;
    scn1.addObject(s1);
    
    Sphere *s2 = new Sphere(Vector(-2, -1, 2), 1);
    s2->mat.color = Color(0, 0, 0);
    s2->mat.diffuse = 0.0;
    s2->mat.specular = 1.0;
    s2->mat.reflectance = 0.5;
    s2->mat.refractance = 0.5;
    s2->mat.mu = 1.3;
    scn1.addObject(s2);
    /*
	Sphere *s3 = new Sphere(v, 0.5);
	s3->mat.color = Color(1, 0, 0);
	s3->mat.reflectance = 0.5;
	s3->mat.refractance = 0.0;
	s3->mat.diffuse = 0.9;
	s3->mat.specular = 0.5;
	s3->mat.mu = 1.25;
	scn1.addObject(s3);
    */
	rt.createImage(scn1);
	rt.writeBMP("output.bmp");
    rt.cleanup();
    
    return 0;
}