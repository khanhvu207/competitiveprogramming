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

const int N=2e5+5;
int n;
int a[N],b[N],c[N],d[N];

template<class T> 
vector<T> z_function(const vector<T>& s){
	int n=sz(s);
	vector<T> z(n);
	for(int i=1,l=0,r=0;i<n;++i){
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) ++z[i];
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];
	REP(i,n) c[i]=a[i]^a[(i+1)%n],d[i]=b[i]^b[(i+1)%n];
	vector<int> s;
	REP(i,n) s.pb(d[i]);
	s.pb(-1);
	FOR(i,n+1,n+n) s.pb(c[i-n-1]);
	FOR(i,n+1+n,n+n+n) s.pb(c[i-n-1-n]);
	vector<int> z=z_function(s);
	REP(i,n)
		if(z[i+n+1]==n) cout<<i<<' '<<(b[0]^a[i])<<'\n';
}

