#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
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
vec tovec (const point &A, const point &B) { return vec(B.x - A.x, B.y - A.y); }
double dist (const point &A, const point &B) { return hypot(A.x - B.x, A.y - B.y); }
double cross (const vec &A, const vec &B) { return A.x * B.y - B.x * A.y; }
double ccw (const point &p, const point &q, const point &r) { return cross(tovec(p, q), tovec(p, r)) > 0; }
double collinear (const point &p, const point &q, const point &r) { return fabs(cross(tovec(p, q), tovec(p, r))) < eps; }

int n;
point pivot;
vector<point> p;

bool grahamScan (const point &L, const point &R)
{
    if (collinear(pivot, L, R))
        return dist(pivot, L) - dist(pivot, R) < 0;
    return ccw(pivot, L, R);
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
        if (P[P0].y > P[i].y || (P[P0].y == P[i].y && P[i].x > P[P0].x)) P0 = i;

    point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;

    pivot = P[0];
    sort(P.begin(), P.end(), grahamScan);

    vector<point> S;
    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);

    int j = 2;
    while (j < n)
    {
        int top = (int)S.size() - 1;
        if (ccw(S[top - 1], S[top], P[j])) S.push_back(P[j++]);
            else S.pop_back();
    }
    return S;
}

int main()
{
    cin >> n;
    for (int i = 0, x, y; i < n; ++i)
    {
        cin >> x >> y;
        p.push_back(point(x, y));
    }
    vector<point> CVH = findCVH(p);
    for (int i = 0; i < (int)CVH.size(); ++i)
        cout << CVH[i].x << ' ' << CVH[i].y << '\n';
}
