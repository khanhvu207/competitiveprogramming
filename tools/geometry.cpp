#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps=1e-9;
const double pi=atan(1)*4;
#define f first
#define s second

struct point 
{
    double x, y;
    point() { x=0, y=0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (const point &r) const
    {
        return fabs(r.x-x)<eps&&fabs(r.y-y)<eps;
    }
};
struct vec 
{
    double x, y;
    vec() { x=0, y=0; }
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec tovec (const point &a, const point &b) { return vec(b.x-a.x, b.y-a.y); }
point mp (const point &a, const point &b) { return point((a.x+b.x)/2.0, (a.y+b.y)/2.0); }
point scale (const point &a, const vec &d) { return point(a.x+d.x, a.y+d.y); }
double cross (const vec &a, const vec &b) { return a.x*b.y-b.x*a.y; }
double dot (const vec &a, const vec &b) { return a.x*b.x+a.y*b.y; }
double dist (const point &a, const point &b) { return hypot(a.x-b.x, a.y-b.y); }

struct point3d
{
    double x, y, z;
    point3d() { x=0, y=0, z=0; }
    point3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
};
struct vec3d
{
    double x, y, z;
    vec3d() { x=0, y=0, z=0; }
    vec3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {} 
};
vec3d tovec (const point3d &a, const point3d &b) { return vec3d(b.x-a.x, b.y-a.y, b.z-a.z); }
double dist (const point3d &a, const point3d &b) { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)); }
double dot3d (const vec3d &a, const vec3d &b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
double cross3d (const vec3d &a, const vec3d &b)
{
    double detx=a.y*b.z-b.y*a.z;
    double dety=a.x*b.z-b.x*a.z;
    double detz=a.x*b.y-b.x*a.y;
    return sqrt(detx*detx+dety*dety+detz*detz);
}