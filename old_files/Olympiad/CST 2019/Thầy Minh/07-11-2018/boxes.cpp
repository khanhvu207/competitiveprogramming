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

struct point {
    double x, y;
    point() { x=0, y=0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (const point &r) const
    {
        return fabs(r.x-x)<eps&&fabs(r.y-y)<eps;
    }
};
struct vec {
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

int n, eliminated = 0;
bool vst[5000];
vec base;
point cp;
vector<point> p;
vector<pair<pair<point, point>, int> > segment;

bool cmp (const pair<pair<double, int>, pair<point, vec> > &a, const pair<pair<double, int>, pair<point, vec> > &b)
{
    return (a.f.f-b.f.f)<-eps;
}

bool hits (point sd, vec dir)
{
    point am=scale(sd, dir);
    vector<pair<pair<double, int>, pair<point, vec> > > d;
    double slp=(am.y-sd.y)/(am.x-sd.x);
    double _b=sd.y-slp*sd.x;
    
    for (int i=0; i<(int)segment.size(); i++)
    {
        if (vst[segment[i].s]) continue;
        point hitpoint;
        vec tdir=dir;
        point a=segment[i].f.f;
        point b=segment[i].f.s;
        vec Ox=tovec(sd, am);
        vec Oa=tovec(sd, a);
        vec Ob=tovec(sd, b);
        if (cross(Ox, Oa)*cross(Ox, Ob)>eps) continue;
        
        if (fabs(a.x-b.x)<eps) ///vertical wall ~ D.x=-D.x
        {
            hitpoint=point(a.x, a.x*slp+_b), tdir.x*=-1.0;
            if (hitpoint==a||hitpoint==b) tdir.y*=-1.0;
        }
        else if (fabs(a.y-b.y)<eps) ///horizontal wall ~ D.y=-D.y
        {
            hitpoint=point((a.y-_b)/slp, a.y), tdir.y*=-1.0;
            if (hitpoint==a||hitpoint==b) tdir.x*=-1.0;
        }
        
        double chk=dot(Ox, tovec(sd, hitpoint)); ///check if result vector & initial vector are pointing the same direction!
        if (chk<-eps) continue;

        d.push_back(make_pair(make_pair(dist(hitpoint, sd), segment[i].s), make_pair(hitpoint, tdir)));
    }
    if ((int)d.size()<1) return false;
    sort(d.begin(), d.end(), cmp);

    eliminated=d[0].f.s;
    vst[d[0].f.s]=1, cp=d[0].s.f, base=d[0].s.s;
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("boxes.inp", "r", stdin);
    freopen("boxes.out", "w", stdout);
    cin >> n;
    double dx, dy;
    cin >> dx >> dy;
    base=tovec(point(0.0, 0.0), point(dx, dy));
    for (int i=1; i<=n; i++)
    {
        double x, y, w, h;
        cin >> x >> y >> w >> h;
        point a=point(x, y);
        point b=point(x+w, y);
        point c=point(x, y+h);
        point d=point(x+w, y+h);
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
        p.push_back(d);
        segment.push_back(make_pair(make_pair(a, b), i));
        segment.push_back(make_pair(make_pair(a, c), i));
        segment.push_back(make_pair(make_pair(b, d), i));
        segment.push_back(make_pair(make_pair(c, d), i));
    }
    cp=point(0.0, 0.0);
    while (hits(cp, base))
        cout << eliminated << '\n';
    return 0;
}

