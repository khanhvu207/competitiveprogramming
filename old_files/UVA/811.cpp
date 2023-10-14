#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
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

int n, v[20], minVal = 1e9, minNum = 1e9, ans, C;
double x[20], y[20], l[20], excess;
point pivot;

bool grahamScan (const point &L, const point &R)
{
    if (collinear(pivot, L, R))
        return dist(pivot, L) - dist(pivot, R) < 0;
    return cross(tovec(pivot, L), tovec(pivot, R)) > 0;
}

vector<point> findCVH (vector<point> P)
{
    int m = (int)P.size();
    if (m <= 3)
    {
        if (!(P[0].x == P[m - 1].x && P[0].y == P[m - 1].y)) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for (int i = 1; i < m; ++i)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
    
    point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;
    pivot = P[0];
    sort(P.begin() + 1, P.end(), grahamScan);

    vector<point> S;
    S.push_back(P[m - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);

    int i = 2;
    while (i < m)
    {
        int top = (int)S.size() - 1;
        if (ccw(S[top - 1], S[top], P[i])) S.push_back(P[i++]);
            else S.pop_back();
    }
    return S;
}

double Perimeter (const vector<point> &A)
{
    double P = 0.0;
    for (int i = 0; i < (int)A.size() - 1; ++i)
        P += dist(A[i], A[i + 1]);
    return P;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        if (n < 1) return 0;
        minVal = 1e9, minNum = 0;

        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i] >> v[i] >> l[i];

        for (int mask = 0; mask < (1 << n); ++mask)
        {
            vector<point> p;
            double logs = 0.0;
            int val = 0;
            for (int i = 0; i < n; ++i)
                if (mask & (1 << i)) p.push_back(point(x[i], y[i]));
                    else logs += l[i], val += v[i];
            
            vector<point> CVH;
            double fence = 0.0;
            if (__builtin_popcount(mask) > 1)
            {
                CVH = findCVH(p);
                fence = Perimeter(CVH);
            }
            if (logs - fence > -eps && val <= minVal)
            {
                if (val == minVal && __builtin_popcount(mask) >= minNum)
                {
                    ans = mask;
                    minNum = __builtin_popcount(mask);
                    excess = logs - fence;
                } else if (val < minVal)
                {
                    ans = mask;
                    minNum = __builtin_popcount(mask);
                    minVal = val;
                    excess = logs - fence;
                }
            }
        }
        if (C > 0)
            cout << '\n';
        cout << "Forest " << ++C << '\n';
        cout << "Cut these trees: ";
        bool first = 1;
        for (int i = 0; i < n; ++i)
            if (!(ans & (1 << i))) 
            {
                if (!first) cout << ' ';
                cout << i + 1;
                first = 0; 
            }
        cout << '\n';
        cout << "Extra wood: ";
        excess = round(excess * 100.0) / 100.0;
        cout << fixed << setprecision(2) << excess << '\n';
    }
}