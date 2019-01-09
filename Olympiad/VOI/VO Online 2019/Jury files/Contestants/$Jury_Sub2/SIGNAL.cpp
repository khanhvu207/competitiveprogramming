#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const double INF = 1e9;

int n, k;
double x[N], y[N], p[N];
double X1[N], X2[N], Y1[N], Y2[N];

void calc_coords(double mul) {
	for (int i = 0; i < n; ++i) {
		double dist = p[i] * mul;
		X1[i] = x[i] - dist;
		X2[i] = x[i] + dist;
		Y1[i] = y[i] - dist;
		Y2[i] = y[i] + dist;
	}
}

vector<int> calc_remain(const vector<int> &a, double x, double y) {
	vector<int> res;
	for (int i : a) {
		if (x < X1[i] || x > X2[i] || y < Y1[i] || y > Y2[i]) res.push_back(i);
	}
	return res;
}

bool ok(const vector<int> &a, double mul, int k) {
	double max_x1 = -INF, max_y1 = -INF;
	double min_x2 = +INF, min_y2 = +INF;
	for (int i : a) {
		max_x1 = max(max_x1, X1[i]);
		max_y1 = max(max_y1, Y1[i]);
		min_x2 = min(min_x2, X2[i]);
		min_y2 = min(min_y2, Y2[i]);
	}
	if (k == 1) {
		return max_x1 <= min_x2 && max_y1 <= min_y2;
	} else {
		// one of two points must cover a corner, another point covers the opposite corner
		if (ok(calc_remain(a, max_x1, max_y1), mul, 1)) return true;
		if (ok(calc_remain(a, max_x1, min_y2), mul, 1)) return true;
		return false;
	}
}

bool ok(double mul) {
	calc_coords(mul);
	vector<int> a;
	for (int i = 0; i < n; ++i) a.push_back(i);
	return ok(a, mul, min(k, 2));
}

int main() {
#ifdef THEMIS
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
#endif // THEMIS


	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> p[i];
	}

	for (int i = 0; i < n; ++i) {
		int p = x[i] - y[i];
		int q = x[i] + y[i];
		x[i] = p;
		y[i] = q;
	}

	double l = 0, r = 1e8;
	for (int it = 0; it < 100; ++it) {
		double mid = (l + r) / 2;
		if (ok(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	cout << setprecision(6) << fixed << (l + r) / 2 << endl;

	return 0;
}
