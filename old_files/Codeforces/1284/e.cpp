// For each point, move it to the origin(0, 0) together with all the other points.
// Sort points according to atan2(y, x).
// Polar sweep + combinatorics.

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define double long double
using namespace std;

const double eps = 1e-9;
const double PI = atan(1) * 4.0;
struct point 
{
    double x, y;
    point() { x=0, y=0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (const point &r) const
    {
        return fabs(r.x-x)<eps&&fabs(r.y-y)<eps;
    }
    bool operator < (const point &r) const {
        return x - r.x < eps;
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
double ccw (const point &p, const point &q, const point &r) { return cross(tovec(p, q), tovec(p, r)) > 0; }

int n;
ll ans;
point O(0, 0);
vector<point> p;

ll C3(ll n) {
    if (n < 3) return 0LL;
    return n * (n - 1LL) * (n - 2LL) / 6LL;
}

ll C4(ll n) {
    if (n < 4) return 0LL;
    return n * (n - 1LL) * (n - 2LL) * (n - 3LL) / 24LL;
}

ll solve(int id) {
    vector<pair<double, point>> a;
    for (int i = 0; i < n; ++i) {
        if (id == i) continue;
        point tmp = point(p[i].x - p[id].x, p[i].y - p[id].y);
        a.push_back(pair<double, point>(atan2(tmp.y, tmp.x) * 180.0 / PI, tmp));
        if (a.back().fi < eps) a.back().fi += 360.0;
    }
    sort(a.begin(), a.end());
    ll ans = C4(n - 1LL);
    for (int L = 0, R = 0; L < (int)a.size(); ++L) {
        while (ccw(O, a[L].se, a[(R + 1) % (int)a.size()].se)) R = (R + 1) % (int)a.size();
        if (L <= R) ans -= C3(L + (int)a.size() - R - 1);
        else ans -= C3(L - (R + 1) % (int)a.size());
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n; ++i) {
        ans += solve(i);
    }
    cout << ans;
}