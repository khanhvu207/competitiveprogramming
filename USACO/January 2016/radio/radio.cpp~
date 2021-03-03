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

const int N = 1005;
int n, m;
int fx[N], fy[N], bx[N], by[N];
ll dp[N][N];

pair<int, int> move(char c) {
	switch (c) {
		case 'N':
			return {0, 1};
		case 'E':
			return {1, 0};
		case 'S':
			return {0, -1};
		case 'W':
			return {-1, 0};
	}
}

void minimize(ll& x, ll y) {
	x = min(x, y);
}

ll dist(ll ax, ll ay, ll bx, ll by) {
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	cin >> n >> m;
	cin >> fx[0] >> fy[0];
	cin >> bx[0] >> by[0];
	string fm, bm;
	cin >> fm >> bm;

	int i = 0;
	for (char c : fm) {
		pair<int, int> mv = move(c);
		++i;
		fx[i] = fx[i - 1] + mv.fi;
		fy[i] = fy[i - 1] + mv.se;
	}
	i = 0;
	for (char c : bm) {
		pair<int, int> mv = move(c);
		++i;
		bx[i] = bx[i - 1] + mv.fi;
		by[i] = by[i - 1] + mv.se;
	}
	
	FOR(i, 0, fm.size()) {
		FOR(j, 0, bm.size()) {
			dp[i][j] = IINF;
		}
	}
	
	dp[0][0] = 0ll;
	FOR(i, 0, fm.size() - 1) {
		FOR(j, 0, bm.size() - 1) {
			minimize(dp[i + 1][j], dp[i][j] + dist(fx[i + 1], fy[i + 1], bx[j], by[j])); 
			minimize(dp[i][j + 1], dp[i][j] + dist(fx[i], fy[i], bx[j + 1], by[j + 1])); 
			minimize(dp[i + 1][j + 1], dp[i][j] + dist(fx[i + 1], fy[i + 1], bx[j + 1], by[j + 1])); 
		}
	}

	cout << dp[int(fm.size())][int(bm.size())] << '\n';
}

