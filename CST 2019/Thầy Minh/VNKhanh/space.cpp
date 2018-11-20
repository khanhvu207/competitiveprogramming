#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-9;

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

int n, m, val[1015];
point3d planet[1015];
double radius[1015], d;
vector<point3d> wp;
bool vst[1015];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("space.inp", "r", stdin);
	freopen("space.out", "w", stdout);
	cin >> n;
	for (int i=0; i<n; ++i)
	{
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		cin >> val[i] >> radius[i];
	}
	cin >> m;
	for (int i=0; i<m; ++i)
	{
		double x, y, z;
		cin >> x >> y >> z;
		if (i<1&&!(fabs(x)<eps&&fabs(y)<eps&&fabs(z)<eps))
			wp.push_back(point3d(0, 0, 0));
		wp.push_back(point3d(x, y, z));
	}
	cin >> d;
	int minerals=0;
	for (int i=1; i<(int)wp.size(); ++i)
		for (int j=0; j<n; ++j)
			if (!vst[j])
			{
				vec3d Oa=tovec(planet[j], wp[i-1]);
				vec3d Ob=tovec(planet[j], wp[i]);
				double h=cross3d(Oa, Ob)/dist(wp[i-1], wp[i]);
				if ((h<=d+radius[j]&&dot3d(tovec(wp[i-1], wp[i]), tovec(wp[i-1], planet[j]))>-eps&&dot3d(tovec(wp[i], wp[i-1]), tovec(wp[i], planet[j]))>-eps)
					|| (dist(wp[i-1], planet[j])<=d+radius[j]) || (dist(wp[i], planet[j])<=d+radius[j]))
					{
						minerals+=val[j];
						vst[j]=1;
					}
			}
	cout << minerals;
	return 0;
}