//
//  Vector.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Vector__
#define __RayTracing__Vector__

# include <cmath>
# include <cstdio>

# define C(V) (V).x, (V).y, (V).z

struct Vector
{
    double x, y, z;
    
    Vector();
    Vector(double a, double b, double c);
    double mag();
    Vector unit();
    void print();
};

Vector operator + (Vector a, Vector b);
Vector operator - (Vector a);
Vector operator - (Vector a, Vector b);
Vector operator * (Vector a, double b);
Vector operator * (double b, Vector a);
Vector operator / (Vector a, double b);

double angle(Vector a, Vector b);
double dot(Vector a, Vector b);
Vector cross(Vector a, Vector b);
Vector project(Vector v, Vector ref);
Vector rotate(Vector v, Vector ref, double angle);

extern Vector I, J, K;

#endif /* defined(__RayTracing__Vector__) */
