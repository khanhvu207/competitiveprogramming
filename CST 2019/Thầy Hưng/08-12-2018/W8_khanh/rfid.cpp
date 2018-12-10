#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps = 1e-9;

struct point
{
    double x, y;
    point() { x = 0.0, y = 0.0; }
    point(double xx, double yy) : x(xx), y(yy) {}
};
struct vec
{
    double x, y;
    vec() { x = 0.0, y = 0.0; }
    vec(double xx, double yy) : x(xx), y(yy) {}
};
vec tovec(const point &a, const point &b) { return vec(b.x-a.x, b.y-a.y); }
double dist(const point &a, const point &b) { return hypot(a.x-b.x, a.y-b.y); }
double cross(const vec &a, const vec &b) { return a.x*b.y-b.x*a.y; }
double ccw(const point &O, const point &A, const point &B) { return cross(tovec(O, A), tovec(O, B))>0; }
double collinear(const point &O, const point &A, const point &B) { return fabs(cross(tovec(O, A), tovec(O, B)))<eps; }

bool cmp (const point &a, const point &b)
{
    if (fabs(a.x-b.x)<eps)
        return a.y<b.y;
    else
        return a.x<b.x;
}

int t, s, w, p;
double r;
vector<point> sensor;
vector<pair<point, point> > walls;

void findSensors(point X)
{
    //cerr << X.x << ' ' << X.y << '\n';
    vector<point> res;
    for (int i=0; i<(int)sensor.size(); ++i)
    {
        double rawdist = dist(X, sensor[i]);
        if (rawdist>r) continue;
        double R=r;
        for (int j=0; j<(int)walls.size(); ++j)
        {
            int t = collinear(X, walls[j].first, sensor[i]) + collinear(X, walls[j].second, sensor[i]);
            double k = cross(tovec(walls[j].first, walls[j].second), tovec(walls[j].first, sensor[i]))*cross(tovec(walls[j].first, walls[j].second), tovec(walls[j].first, X));
            if (k>0) continue;
            if (t>0)
            {
                //if (t==2)
                    R -= 1.0;
                continue;
            }
            double f = cross(tovec(X, walls[j].first), tovec(X, sensor[i]))*cross(tovec(X, walls[j].second), tovec(X, sensor[i]));
            //cerr << i << ' ' << j << ' ' << f << '\n';
            R -= (f<0)*1.0;
        }
        //cerr << sensor[i].x << ' ' << sensor[i].y << ' ' << R << '\n';
        if (rawdist-R<=eps)
            res.push_back(sensor[i]);
    }
    cout << (int)res.size() << ' ';
    sort(res.begin(), res.end(), cmp);
    for (int i=0; i<(int)res.size(); ++i)
        cout << '(' << res[i].x << ',' << res[i].y << ')' << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("rfid.inp", "r", stdin);
    freopen("rfid.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> s >> r >> w >> p;
        for (int i = 0; i<s; ++i)
        {
            double sx, sy;
            cin >> sx >> sy;
            sensor.push_back(point(sx, sy));
        }
        for (int i = 0; i<w; ++i)
        {
            double bx, by, ex, ey;
            cin >> bx >> by >> ex >> ey;
            walls.push_back(pair<point, point>(point(bx, by), point(ex, ey)));
        }
        for (int i = 1; i<=p; ++i)
        {
            double fx, fy;
            cin >> fx >> fy;
            findSensors(point(fx, fy));
            //return 0;
        }
    }
}
