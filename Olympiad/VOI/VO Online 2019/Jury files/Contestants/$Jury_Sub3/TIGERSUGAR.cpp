// x1=x2=0 => 1D problem

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int64_t X1[N], X2[N], Y1[N], Y2[N];
int n;

vector<int64_t> solve(int64_t L[], int64_t R[]) {
	map< int64_t, vector<int> > add, rem;
	set< int64_t > coords;

	for (int i = 1; i <= n; ++i) {
		add[L[i]].push_back(i);
		rem[R[i]].push_back(i);
		coords.insert(L[i]);
		coords.insert(R[i]);
	}

	int64_t best_x = -1;
	int64_t best_cost = 0;
	int64_t cnt_left = 0, sum_left = 0;
	int64_t cnt_right = 0, sum_right = 0;

	for (int i = 1; i <= n; ++i) {
		cnt_right += 1;
		sum_right += L[i];
	}

	for (int64_t x : coords) {
		for (int i : add[x]) {
			cnt_right -= 1;
			sum_right -= x;
		}

		int64_t cur = 0;
		cur += x * cnt_left - sum_left;
		cur += sum_right - x * cnt_right;
		if (best_cost > cur || best_x == -1) {
			best_cost = cur;
			best_x = x;
		}

		for (int i : rem[x]) {
			cnt_left += 1;
			sum_left += x;
		}
	}

	vector< int64_t > res;
	for (int i = 1; i <= n; ++i) {
		if (R[i] < best_x) {
			res.push_back(R[i]);
		} else if (best_x < L[i]) {
			res.push_back(L[i]);
		} else {
			res.push_back(best_x);
		}
	}
	res.push_back(best_x);
	res.push_back(best_cost);

	return res;
}

int main() {
#ifdef THEMIS
    freopen("TIGERSUGAR.INP", "r", stdin);
    freopen("TIGERSUGAR.OUT", "w", stdout);
#endif // THEMIS

	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		assert(X1[i] == 0); assert(X2[i] == 0);
		if (Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);
	}
	vector<int64_t> res = solve(Y1, Y2);

	cout << res.back() << '\n';
	cout << 0 << ' ' << res[n] << '\n';
	for (int i = 0; i < n; ++i) {
		cout << 0 << ' ' << res[i] << '\n';
	}

	return 0;
}
