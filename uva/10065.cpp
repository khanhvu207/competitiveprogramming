#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const double eps = 1e-9;

struct point 
{
    double x, y;
    point() { x = 0, y = 0; }
    point(double xx, double yy) : x(xx), y(yy) {}
};
struct vec
{
    double x, y;
    vec() { x = 0, y = 0; }
    vec(double xx, double yy) : x(xx), y(yy) {}
};
vec tovec (const point &a, const point &b) { return vec(b.x - a.x, b.y - a.y); }
double cross (const vec &a, const vec &b) { return (a.x * b.y - b.x * a.y); }
double dist (const point &a, const point &b) { return hypot(a.x - b.x, a.y - b.y); }
bool collinear (const point &O, const point &a, const point &b) { return fabs(cross(tovec(O, a), tovec(O, b))) < eps; }
bool ccw (const point &O, const point &a, const point &b) { return cross(tovec(O, a), tovec(O, b)) > 0; }

int n, C = 0;
point pivot;
vector<point> p, CVH;

bool grahamScan (const point &L, const point &R)
{
    if (collinear(pivot, L, R))
        return dist(pivot, L) - dist(pivot, R) < eps;
    return cross(tovec(pivot, L), tovec(pivot, R)) > 0;
}

vector<point> findCVH (vector<point> P)
{
    if (n <= 3)
    {
        if (!(P[0].x == P[n - 1].x && P[0].y == P[n - 1].y)) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for (int i = 1; i < n; ++i)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
    
    point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;

    pivot = P[0];
    sort(P.begin() + 1, P.end(), grahamScan); 

    vector<point> S;
    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    int i = 2;
    while (i < n)
    {
        int top = (int)S.size() - 1;
        if (ccw(S[top - 1], S[top], P[i])) S.push_back(P[i++]);
            else S.pop_back();
    }
    return S;
}

double areaPoly (const vector<point> &Poly)
{
    double S = 0.0;
    point Origin = point(0, 0);
    for (int i = 0; i < (int)Poly.size() - 1; ++i)
        S += cross(tovec(Origin, Poly[i]), tovec(Origin, Poly[i + 1]));
    S = fabs(S / 2.0);
    return S;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        if (n < 1) return 0;
        p.clear();
        for (int i = 0; i < n; ++i)
        {
            double x, y; cin >> x >> y;
            p.push_back(point(x, y));
        }      
        CVH = findCVH(p);
        p.push_back(p[0]);
        double res = (1.0 - areaPoly(p) / areaPoly(CVH)) * 100.0;
        cout << "Tile #" << ++C << '\n' << "Wasted Space = ";
        cout << fixed << setprecision(2) << res << " %\n"; cout << '\n';
    }
}