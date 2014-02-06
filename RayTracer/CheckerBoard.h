//
//  CheckerBoard.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__CheckerBoard__
#define __RayTracing__CheckerBoard__

# include "Plane.h"

struct CheckerBoard : Plane
{
    Vector u, v;
    Color col1, col2;
    double size;
    
    CheckerBoard(Vector pp, Vector normal, Vector u, double size = 1);
    Material getMaterial(Vector p);
};

#endif /* defined(__RayTracing__CheckerBoard__) */
 