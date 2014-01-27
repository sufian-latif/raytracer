//
//  Color.h
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

#ifndef __RayTracing__Color__
#define __RayTracing__Color__

struct Color
{
	double r, g, b;
    
	Color();
	Color(double r, double g, double b);
	void normalize();
};

Color operator * (double p, Color c);
Color operator * (Color c, double p);
Color operator + (Color c1, Color c2);
Color operator * (Color a, Color b);


#endif /* defined(__RayTracing__Color__) */
