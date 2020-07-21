// For each point, move it to the origin(0, 0) together with all the other points.
// Sort points according to atan2(y, x).
// Polar sweep + combinatorics.
 
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define double long double
using namespace std;
 
const double eps = 1e-7;
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
    ll a[4] = {0};
    vector<double> angle;
    for (int i = 0; i < n; ++i) {
        if (id == i) continue;
        point tmp = point(p[i].x - p[id].x, p[i].y - p[id].y);
        angle.push_back(atan2(tmp.y, tmp.x) * 180.0 / PI);
        if (angle.back() < eps) angle.back() += 360.0;
        if (angle.back() - 90.0 < eps) ++a[0];
        else if (angle.back() - 180.0 < eps) ++a[1];
        else if (angle.back() - 270.0 < eps) ++a[2];
        else ++a[3];
    }
    sort(angle.begin(), angle.end());
    ll ans = C4(a[0] + a[1] + a[2] + a[3]);
    for (int i = 0; i < n - 1; ++i) {
        if (i < a[0] + a[1]) {
            cerr << i + n - 1 - (upper_bound(angle.begin(), angle.end(), angle[i] + 180.0 - eps) - angle.begin()) << '\n';
            ans -= C3(i + n - 1 - (upper_bound(angle.begin(), angle.end(), angle[i] + 180.0 - eps) - angle.begin()));
        }
        else {
            cerr << i - (upper_bound(angle.begin(), angle.end(), angle[i] - 180.0 + eps) - angle.begin()) << '\n';
            ans -= C3(i - (upper_bound(angle.begin(), angle.end(), angle[i] - 180.0 + eps) - angle.begin()));
        }
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    for (int i = 2; i < 3; ++i) {
        // cerr << i << ' ' << solve(i) << '\n';
        ans += solve(i);
    }
    cout << ans;
}