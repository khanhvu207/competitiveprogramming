#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define TLE() cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms.\n";
const ll MOD = 1E9+7;
const ll IINF = 1E18;
const int INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N = 205;
int n;
vector<pair<int, int>> p;
vector<int> encoded;

bool check(int step, int idx) {
	int len = step * 2 + 1;
	bool res = false;
	FOR(i, 1, n - 2) {
		int st = 2 * (i - 1);
		bool flag = true;
		FOR(j, st, st + len - 1) {
			if (j >= sz(encoded)) {
				flag = false;
				break;
			}
			flag &= encoded[j] == encoded[2 * (idx - 1) + j - st];
		}
		res |= flag;
	}
	return !res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("lightsout.in", "r", stdin);
	freopen("lightsout.out", "w", stdout);
	cin >> n;
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		p.eb(x, y);
	}
	FOR(i, 1, n - 2) {
		if (p[i - 1].fi == p[i].fi) {
			if (p[i - 1].se < p[i].se) {
				if (p[i].fi < p[i + 1].fi) encoded.pb(0);
				else encoded.pb(-1);
			} 
			else {
				if (p[i].fi > p[i + 1].fi) encoded.pb(0);
				else encoded.pb(-1);
			}
		}
		else {
			if (p[i - 1].fi < p[i].fi) {
				if (p[i].se > p[i + 1].se) encoded.pb(0);
				else encoded.pb(-1);
			}
			else {
				if (p[i].se < p[i + 1].se) encoded.pb(0);
				else encoded.pb(-1);
			}
		}
		int dist = abs(p[i].fi - p[i + 1].fi) + abs(p[i].se - p[i + 1].se);
		encoded.pb(dist);
	}
	int res = 0;
	int peri = 0;
	REP(i, n) 
		peri += abs(p[i].fi - p[(i + 1) % n].fi) + abs(p[i].se - p[(i + 1) % n].se);
	FOR(i, 1, n - 2) {
		int idx = 2 * (i - 1);
		int l = 1, r = n - 1 - i;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (!check(m, i)) l = m + 1;
			else r = m - 1;
		}
//		cerr << i << ' ' << l << '\n';
		assert((i + l) < n);
		int dist_to_exit = 0;
		int dist_return = 0;
		FOR(j, i, n - 1) 
			dist_to_exit += abs(p[j].fi - p[(j + 1) % n].fi) + abs(p[j].se - p[(j + 1) % n].se);
		FOR(j, 1, l)
			dist_return += abs(p[i + j - 1].fi - p[(i + j) % n].fi) + abs(p[i + j - 1].se - p[(i + j) % n].se);
		FOR(j, 0, i + l - 1)
			dist_return += abs(p[j].fi - p[j + 1].fi) + abs(p[j].se - p[j + 1].se);
		int ans = min(dist_to_exit, dist_return);
		int real_dist = 0;
		FOR(j, 0, i - 1)
			real_dist += abs(p[j].fi - p[j + 1].fi) + abs(p[j].se - p[j + 1].se);
		real_dist = min(real_dist, peri - real_dist);
		res = max(res, ans - real_dist);
	}
	cout << res << '\n';
}

