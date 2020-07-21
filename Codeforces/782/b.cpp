#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 60005;
const double eps = 1e-9;
int n;
double x[N], v[N];

bool chk(double t) {
	double L = -1e18, R = 1e18;
	for (int i = 0; i < n; ++i) 
		L = fmax(L, x[i] - t * v[i]), R = fmin(R, x[i] + t * v[i]);
	return L - R <= eps;
}

int main() {
#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> v[i];
	double l = eps, r = 1e9;
	for (int i = 0; i < 166; ++i) {
		double m = (l + r) / 2.0;
		if (chk(m)) r = m - eps;
		else l = m + eps;
	}
	double ans = (l + r) / 2.0;
	cout << fixed << setprecision(8) << ans;
}