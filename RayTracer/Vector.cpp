//
//  Vector.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#include "Vector.h"

using namespace std;

Vector::Vector()
{
    x = 0; y = 0; z = 0;
}

Vector::Vector(double a, double b, double c)
{
    x = a, y = b, z = c;
}

double Vector::mag()
{
    return sqrt(x*x + y*y + z*z);
}

Vector Vector::unit()
{
    double m = mag();
    if(m < 0.0000001) return Vector();
    return Vector(x/m, y/m, z/m);
}

void Vector::print()
{
    printf("(%lf, %lf, %lf)\n", x, y, z);
}

Vector operator + (Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator - (Vector a)
{
    return Vector(-a.x, -a.y, -a.z);
}

Vector operator - (Vector a, Vector b)
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator * (Vector a, double b)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}

Vector operator * (double b, Vector a)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}

Vector operator / (Vector a, double b)
{
    return Vector(a.x / b, a.y / b, a.z / b);
}

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double angle(Vector a, Vector b)
{
    return acos(dot(a.unit(), b.unit()));
}

Vector cross(Vector a, Vector b)
{
    return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

Vector project(Vector v, Vector ref)
{
    return ref.unit() * dot(v, ref.unit());
}

Vector rotate(Vector v, Vector ref, double angle)
{
    Vector hor = project(v, ref);
    Vector ver = v - hor;
    Vector per = cross(ref, ver);
    Vector rot = ver.unit() * cos(angle) + per.unit() * sin(angle);
    return rot * ver.mag() + hor;
}

Vector I(1, 0, 0);
Vector J(0, 1, 0);
Vector K(0, 0, 1);
