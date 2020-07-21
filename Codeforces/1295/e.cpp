#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, p[N], a[N], q[N];
ll st[4 * N], lz[4 * N];

void upd(int id, int tl, int tr, int L, int R, ll v) {
	if (tl > R || tr < L) return;
	if (L <= tl && tr <= R) {
		lz[id] += v;
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(id << 1, tl, tm, L, R, v);
	upd(id << 1 | 1, tm + 1, tr, L, R, v);
	st[id] = min(st[id << 1] + lz[id << 1], st[id << 1 | 1] + lz[id << 1 | 1]);
}

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		q[--p[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		upd(1, 0, n - 2, i, n - 2, a[i]);
	}
	ll res = st[1] + lz[1];
	for (int i = 0; i < n; ++i) {
		int j = q[i];
		upd(1, 0, n - 2, 0, j - 1, a[j]);
		upd(1, 0, n - 2, j, n - 2, -a[j]);
		res = min(res, st[1] + lz[1]);
	}
	cout << res;
}