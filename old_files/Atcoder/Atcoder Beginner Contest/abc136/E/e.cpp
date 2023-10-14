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

const int N=555;
int n,k,a[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	REP(i,n) cin>>a[i];
	int sum=accumulate(a,a+n,0);
	int res=1;
	auto check=[&](int x)->bool{
		int tot=0;
		int used=0;
		vector<int> t;
		REP(i,n) t.pb(a[i]%x),tot+=x-a[i]%x;
		sort(all(t));
		REP(i,n){
			used+=t[i];
			tot-=x-t[i];
			if(used==tot&&used<=k) return true;
		}
		return false;
	};
	for(int i=1;i*i<=sum;++i){
		if(sum%i!=0) continue;
		if(check(i)) res=max(res,i);
		if(i*i!=sum&&check(sum/i)) res=max(res,sum/i);
	}
	cout<<res<<'\n';
}
// invariant factor: S = sum of Ai is unchanged
// for every divisor of S, we check whether if it's possible or not
