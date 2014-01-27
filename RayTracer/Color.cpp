//
//  Color.cpp
//  RayTracing
//
//  Created by Sufian Latif on 1/24/14.
//
//

# include "Color.h"
# include <algorithm>

using namespace std;

Color::Color()
{
    r = g = b = 0;
}

Color::Color(double r, double g, double b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	normalize();
}

void Color::normalize()
{
	double s = max(r, max(g, b));
	if(s > 1)
	{
		r /= s;
		g /= s;
		b /= s;
	}
}

Color operator * (double p, Color c)
{
	Color cc(c.r * p, c.g * p, c.b * p);
	cc.normalize();
	return cc;
}

Color operator * (Color c, double p)
{
    Color cc(p * c.r, p * c.g, p * c.b);
    cc.normalize();
	return cc;
}

Color operator + (Color c1, Color c2)
{
	Color cc(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
	cc.normalize();
	return cc;
}

Color operator * (Color c1, Color c2)
{
	Color cc(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
	cc.normalize();
	return cc;
}
