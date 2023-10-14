/*input
3 1
1 1 1
2 2 1
3 3 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
//const int N=;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
struct data {
	int x, y, p;
	data(int _x, int _y, int _p): x(_x), y(_y), p(_p) {};
};

pair<double, double> ans[5];

void convert(double diff, double sum, int p) {
	ans[p].fi = (sum + diff) / 2;
	ans[p].se = (sum - diff) / 2;
}

bool solve(int lev, vector<data> people, const double dis) {
	/*
		-T+xA - yA <=  (xB - yB) <= T + xA - yA // 0
		-T+xA + yA  <= (xB + yB) <= T + xA + yA // 1
	*/
	double lo[2], hi[2];
	lo[0] = lo[1] = -1e18;
	hi[0] = hi[1] = 1e18;
	for (auto it : people) {
		double T = dis * it.p;
		lo[0] = max(lo[0], -T + it.x - it.y); hi[0] = min(hi[0], T + it.x - it.y);
		lo[1] = max(lo[1], -T + it.x + it.y); hi[1] = min(hi[1], T + it.x + it.y);
	}
	if (lev == 1) {
		if (lo[0] > hi[0] || lo[1] > hi[1]) return false;
		convert(lo[0], lo[1], lev);
		return true;
	}
	loop(p1, 0, 1) {
		loop(p2, 0, 1) {
			vector<data> npeople;
			double x = (p1 == 0 ? lo[0] : hi[0]), y = (p2 == 0 ? lo[1] : hi[1]);
			convert(x, y, lev);
			for (auto it : people) {
				double T = dis * it.p;
				if (-T + it.x - it.y <= x && x <= T + it.x - it.y && -T + it.x + it.y <= y && y <= T + it.x + it.y);
				else npeople.push_back(it);
			}
			if (solve(lev - 1, npeople, dis)) return true;
		}
	}
	return false;
}

int n, m;
vector<data> people;

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

#ifdef THEMIS
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
#endif // THEMIS

#ifdef in1code
	freopen("1test.inp", "r", stdin);
#endif
	cin >> n >> m;
	loop(i, 1, n) {
		int x, y, p; cin >> x >> y >> p;
		people.push_back(data(x, y, p));
	}
	double l = 0, r = 2e7;
	loop(i, 1, 100) {
		double mid = (l + r) / 2;
		if (solve(m, people, mid)) r = mid;
		else l = mid;
	}
	cout << setprecision(6) << fixed << l << endl;
}
