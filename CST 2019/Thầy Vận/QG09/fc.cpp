#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-9;

struct point
{
    double x, y;
    point() { x=0.0, y=0.0; }
    point(double xx, double yy) : x(xx), y(yy) {}
};
struct vec
{
    double x, y;
    vec() { x=0.0, y=0.0; }
    vec(double xx, double yy) : x(xx), y(yy) {}
};
vec tovec(const point &a, const point &b) { return vec(b.x-a.x, b.y-a.y); }
double dist(const point &a, const point &b) { return hypot(a.x-b.x, a.y-b.y); }
double cross(const vec &a, const vec &b) { return a.x*b.y-b.x*a.y; }
double ccw(const point &O, const point &A, const point &B) { return cross(tovec(O, A), tovec(O, B))>0; }
double collinear(const point &O, const point &A, const point &B) { return fabs(cross(tovec(O, A), tovec(O, B)))<eps; }

int n;
point pivot;
vector<point> p;

bool grahamScan(const point &L, const point &R)
{
    if (collinear(pivot, L, R))
        return dist(pivot, L)-dist(pivot, R)<0;
    return ccw(pivot, L, R);
}

vector<point> findCVH(vector<point> P)
{
    if (n<=3)
    {
        if (!(P[0].x==P[n-1].x&&P[0].y==P[n-1].y)) P.push_back(P[0]);
        return P;
    }
    int P0=0;
    for (int i=1; i<n; ++i)
        if (P[i].y<P[P0].y||(P[i].y==P[P0].y&&P[i].x>P[P0].x)) P0=i;
    point tmp=P[0]; P[0]=P[P0]; P[P0]=tmp;
    pivot=P[0];
    sort(P.begin()+1, P.end(), grahamScan);
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    int i=2;
    while (i<n)
    {
        int top=(int)S.size()-1;
        if (ccw(S[top-1], S[top], P[i])) S.push_back(P[i++]);
            else S.pop_back();
    }
    return S;
}

double Perimeter(const vector<point> &C)
{
    double sum=0.0;
    for (int i=0; i<(int)C.size()-1; ++i)
        sum+=dist(C[i], C[i+1]);
    return sum;
}

void Input()
{
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        double x, y;
        cin >> x >> y;
        p.push_back(point(x, y));
    }
}

void Solve()
{
    vector<point> CVH=findCVH(p);
    cout << fixed << setprecision(2) << Perimeter(CVH);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("fc.inp", "r", stdin);
    freopen("fc.out", "w", stdout);
    Input();
    Solve();
}
