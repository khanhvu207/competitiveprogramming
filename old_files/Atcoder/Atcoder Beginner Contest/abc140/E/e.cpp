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
int pos[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n){
		int x;
		cin>>x;
		pos[x]=i;
	}
	set<int> s;
	ll res=0;
	FORD(i,n,1){
		int cur=pos[i];
		auto it=s.lower_bound(cur);
		auto l=it;
		auto r=it;
		int c=(it==s.end())?n:*it;
		if(it!=s.end()) ++r;
		int d=(r==s.end())?n:*r;
		if(it!=s.begin()) --l;
		int b=(l==it)?-1:*l;
		int a=(l==s.begin())?-1:*(--l);
		ll t=0;
		if(c!=n) t+=(d-c)*(cur-b);
		if(b!=-1) t+=(b-a)*(c-cur);
//		cerr<<i<<' '<<t<<'\n';
//		cerr<<a<<' '<<b<<' '<<cur<<' '<<c<<' '<<d<<'\n';
		res+=t*i;
		s.insert(pos[i]);
	}
	cout<<res<<'\n';	
}

