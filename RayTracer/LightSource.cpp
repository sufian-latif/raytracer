//
//  LightSource.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/26/14.
//
//

# include "LightSource.h"

LightSource::LightSource(Vector c, double r, double in) : Sphere(c, r)
{
    intensity = in;
}

bool LightSource::isLightSource()
{
    return true;
}

Color LightSource::getColor()
{
    return mat.diffuse;
}
