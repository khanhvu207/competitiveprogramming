// all rectangles are points => answer = (median_x, median_y)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int X1[N], X2[N], Y1[N], Y2[N];
int n;

int main() {
#ifdef THEMIS
    freopen("TIGERSUGAR.INP", "r", stdin);
    freopen("TIGERSUGAR.OUT", "w", stdout);
#endif // THEMIS

	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		assert(X1[i] == X2[i]);
		assert(Y1[i] == Y2[i]);
		x[i] = X1[i];
		y[i] = Y1[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int best_x = x[n / 2];
	int best_y = y[n / 2];
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += abs(x[i] - best_x);
		sum += abs(y[i] - best_y);
	}
	cout << sum << endl;
	cout << best_x << ' ' << best_y << endl;
	for (int i = 0; i < n; ++i) {
		cout << X1[i] << ' ' << Y1[i] << '\n';
	}

	return 0;
}
