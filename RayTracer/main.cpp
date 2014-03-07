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
# include "CheckerBoard.h"
# include "Cylinder.h"
# include "LightSource.h"
# include "Material.h"

int main()
{
    Vector camPos = Vector(0, 0, 10);
	Vector v;
	RayTracer rt = RayTracer(camPos, -K, J, 800, 800, 4);
	Scene scn1 = Scene(Color(0.2, 0.2, 0.2), Color(0.5, 0.5, 0.5));
    
	loadMaterials("materials.txt");
    
    // add objects here
    
	rt.createImage(scn1);
	rt.writeBMP("output.bmp");
    rt.cleanup();
    
    return 0;
}