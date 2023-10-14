#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1);

struct point {
  double x, y;
  point(double xx, double yy) {
    this -> x = xx;
    this -> y = yy;
  }
};
struct vec {
  double x, y;
  vec(double xx, double yy) {
    this -> x = xx;
    this -> y = yy;
  }
};
vec tovec(const point &a, const point &b) {
  return vec(b.x - a.x, b.y - a.y);
}
double cross(const vec &a, const vec &b) {
  return a.x * b.y - b.x * a.y;
}
double dot(const vec &a, const vec &b) {
  return a.x * b.x + a.y * b.y;
}
double dist(const point &a, const point &b) {
  return hypot(a.y - b.y, a.x - b.x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("giaodiem.inp", "r", stdin);
  freopen("giaodiem.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc--) {
    bool res = false;
    double sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    vector<pair<point, point> > seg;
    double xl, yt, xr, yb;
    cin >> xl >> yt >> xr >> yb;
    seg.push_back({point(xl, yt), point(xl, yb)});
    seg.push_back({point(xl, yb), point(xr, yb)});
    seg.push_back({point(xr, yb), point(xr, yt)});
    seg.push_back({point(xr, yt), point(xl, yt)});
    double angle_1 = 0.0;
    double angle_2 = 0.0;
    for (int i = 0; i < 4; ++i) {
      if (fabs(cross(tovec(point(sx, sy), seg[i].first), tovec(point(sx, sy), seg[i].second))) < eps) {
        res = true;
        break;
      }
      vec base = tovec(point(sx, sy), point(ex, ey));
      vec _base = tovec(seg[i].first, seg[i].second);
      if (cross(base, tovec(point(sx, sy), seg[i].first)) * cross(base, tovec(point(sx, sy), seg[i].second)) < -eps &&
            cross(_base, tovec(seg[i].first, point(sx, sy))) * cross(_base, tovec(seg[i].first, point(ex, ey))) < -eps) {
              res = true;
              break;
            }
      angle_1 += acos(dot(tovec(point(sx, sy), seg[i].first), tovec(point(sx, sy), seg[i].second)) / (dist(point(sx, sy), seg[i].first) * dist(point(sx, sy), seg[i].second)));
      angle_2 += acos(dot(tovec(point(ex, ey), seg[i].first), tovec(point(ex, ey), seg[i].second)) / (dist(point(ex, ey), seg[i].first) * dist(point(ex, ey), seg[i].second)));
    }
    if (fabs(angle_1 - 2.0 * pi) <= eps && fabs(angle_2 - 2.0 * pi) <= eps) {
      res = true;
    }
    if (res)
      cout << "T\n";
    else
      cout << "F\n";
  }
}
