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
ll n,x,d,res;
unordered_map<ll,vector<pair<ll,ll>>> Map;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x>>d;
	if(d==0){
		if(x==0) exit(puts("1\n")*0);
		else{
			cout<<n+1<<'\n';
			return 0;
		}
	}
	if(x==0){
		cout<<1LL+n*(n-1LL)/2LL<<'\n';
		return 0;
	}
	FOR(i,0,n){
		ll k=i*x;
		ll pf=i*(i-1LL)/2LL;
		ll sf=(n-i)*i+pf;
		Map[k%d].pb(mp(k/d+pf,k/d+sf));
	}
	for(auto &it:Map){
		auto &v=it.se;
		sort(all(v));
		ll l=v[0].fi;
		ll r=v[0].se;
		FOR(i,1,sz(v)-1){
			if(v[i].fi<=r) r=max(r,v[i].se);
			else{
			   res+=r-l+1;
			   l=v[i].fi;
			   r=v[i].se;
			}
		}
		res+=r-l+1;
	}
	cout<<res<<'\n';
}

