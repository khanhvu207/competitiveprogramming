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
};
struct vec {
    double x, y;
    vec() { x=0, y=0; }
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec tovec (const point &a, const point &b) { return vec(b.x-a.x, b.y-a.y); }
point mp (const point &a, const point &b) { return point((a.x+b.x)/2.0, (a.y+b.y)/2.0); }
double cross (const vec &a, const vec &b) { return a.x*b.y-b.x*a.y; }
double dot (const vec &a, const vec &b) { return a.x*b.x+a.y*b.y; }
double dist (const point &a, const point &b) { return hypot(a.x-b.x, a.y-b.y); }

string buffer_;
int n, cnt = 0;
bool vst[5000];
point center=point(0.0, 0.0);
vector<pair<pair<point, point>, int> > segment;
vector<point> p;
vector<pair<double, int> > v;

void checking (point m)
{
    vector<pair<double, int> > d;
    double slp=m.y/m.x;
    for (int i=0; i<(int)segment.size(); i++)
    {
        point cutpoint;
        point a=segment[i].f.f;
        point b=segment[i].f.s;
        vec Om=tovec(center, m);
        vec Oa=tovec(center, a);
        vec Ob=tovec(center, b);
        if (!(cross(Om, Oa)*cross(Om, Ob)<-eps)) continue;
        if (a.x==b.x) ///vertical case
            cutpoint=point(a.x, a.x*slp);
        else
        if (a.y==b.y) ///horizontal case
            cutpoint=point(a.y/slp, a.y);
        
        double chk=dot(Om, tovec(center, cutpoint));
        if (chk<-eps) continue;

        d.push_back(make_pair(dist(center, cutpoint), segment[i].s));
    }
    sort(d.begin(), d.end());
    if ((int)d.size()>0&&!vst[d[0].s])
    {
        ++cnt;
        vst[d[0].s]=1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);
    cin >> n; getline(cin, buffer_);
    for (int i=0; i<n; i++)
    {
        double x, y, len;
        cin >> x >> y >> len; getline(cin, buffer_);
        point a=point(x, y);
        point b=point(x+len, y);
        point c=point(x, y+len);
        point d=point(x+len, y+len);
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
        p.push_back(d);
        segment.push_back(make_pair(make_pair(a, b), i));
        segment.push_back(make_pair(make_pair(a, c), i));
        segment.push_back(make_pair(make_pair(b, d), i));
        segment.push_back(make_pair(make_pair(c, d), i));
    }
    vec base=tovec(center, point(2999.0, 0.0));
    for (int i=0; i<(int)p.size(); i++)
    {
        vec Oi=tovec(center, p[i]);
        double agl=atan(cross(base, Oi)/dot(base, Oi));
        agl=fabs(agl*180.0/pi);
        if (fabs(cross(base, Oi))<eps)
        {
            if (dot(base, Oi)<-eps)
                agl=180.0;
            else
                agl=0.0;
        } else
        {
            if (cross(base, Oi)<-eps)
                agl=360.0-agl-((dot(base, Oi)<-eps)?90.0:0.0);
            else
                agl+=(dot(base, Oi)<-eps?90.0:0.0);
        }
        v.push_back(make_pair(agl, i));
    }
    sort(v.begin(), v.end());
    for (int i=1; i<(int)v.size(); i++)
    {
        point midpoint;
        if (fabs(v[i].f-v[i-1].f)<eps)
            midpoint=p[v[i].second];
        else
            midpoint=mp(p[v[i].second], p[v[i-1].second]);
        checking(midpoint);
    }
    cout << cnt;
    return 0;
}
