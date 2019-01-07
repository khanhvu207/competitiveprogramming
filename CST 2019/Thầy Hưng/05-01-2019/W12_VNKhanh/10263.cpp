#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1);

struct point {
  double x, y;
  point() { x = 0.0, y = 0.0; }
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
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("10263.inp", "r", stdin);
  freopen("10263.out", "w", stdout);
  double mx, my;
  while (cin >> mx >> my) {
    double best = 1e18, resx = mx, resy = my;
    point M = point(mx, my);
    int r;
    cin >> r;
    double px, py;
    cin >> px >> py;
    for (int i = 0; i < r; ++i) {
      double ax, ay;
      cin >> ax >> ay;
      point A = point(px, py);
      point B = point(ax, ay);
      if (fabs(cross(tovec(M, A), tovec(M, B))) < eps) {
        if (dist(M, A) < best) {
          resx = A.x;
          resy = A.y;
          best = dist(M, A);
        }
        if (dist(M, B) < best) {
          resx = B.x;
          resy = B.y;
          best = dist(M, B);
        }
        px = ax;
        py = ay;
        continue;
      }
      vec e = tovec(A, B);
      double cos_angle = dot(tovec(A, M), tovec(A, B)) / (dist(A, M) * dist(A, B));
      double AX = cos_angle * dist(A, M);
      double h = sqrt(dist(A, M) * dist(A, M) - AX * AX);
      double tx = A.x + (AX / dist(A, B)) * e.x;
      double ty = A.y + (AX / dist(A, B)) * e.y;
      point H = point(tx, ty);
      if (fabs(dist(A, H) + dist(H, B) - dist(A, B)) > eps) {
         if (dist(M, A) < best) {
          resx = A.x;
          resy = A.y;
          best = dist(M, A);
        }
        if (dist(M, B) < best) {
          resx = B.x;
          resy = B.y;
          best = dist(M, B);
        }
        px = ax;
        py = ay;
        continue;
      }
      if (h - best < -eps) {
        resx = tx;
        resy = ty;
        best = h;
      }
      px = ax;
      py = ay;
    }
    cout << fixed << setprecision(4) << resx << '\n' << resy << '\n';
  }
}
