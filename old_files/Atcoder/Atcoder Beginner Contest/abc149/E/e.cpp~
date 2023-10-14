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

const int N=1e5+5;
int n;
ll m;
ll a[N],pf[N];

ll calc(ll x){
	ll cnt=0;
	ll sum=0;
	REPD(i,n){
		int pos=lower_bound(a,a+n,x-a[i])-a;
		cnt+=n-pos;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	pf[0]=a[0];
	FOR(i,1,n-1) pf[i]=pf[i-1]+a[i];
	ll l=0,r=1e6;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(calc(mid)>=m) l=mid+1;
		else r=mid-1;
	}
	ll res=0;
	REPD(i,n){
		int pos=lower_bound(a,a+n,r+1-a[i])-a;
		if(pos>=n) continue;
		res+=(n-pos)*a[i]+pf[n-1]-(pos?pf[pos-1]:0);
		m-=n-pos;
	}
	res+=max(0LL,m)*r;
	cout<<res<<'\n';
}

