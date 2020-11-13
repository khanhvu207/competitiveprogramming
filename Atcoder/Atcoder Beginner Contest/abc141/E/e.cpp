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

const int N=5005;
const ll base=311;

int n;
string s;

bool check(int len){
	ll k=1;
	REP(i,len-1) k=k*base%MOD;
	ll hash=0;
	unordered_map<ll,vector<int>> Map;
	REP(i,n-len+1){
		if(i==0){
			REP(j,len) 
				hash=(hash*base+s[j]-48)%MOD;
		}else{
			hash-=(s[i-1]-48)*k%MOD;
			if(hash<0) hash+=MOD;
			hash=(hash*base+s[i+len-1]-48)%MOD;
		}
		if(Map.count(hash)){
			auto& v=Map[hash];
			auto lb=lower_bound(all(v),i-len);
			if(lb!=v.begin()&&*lb>i-len) --lb;
			if(*lb<=i-len)
				return true;
		}
		Map[hash].pb(i);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	cin>>s;
	int l=1,r=n;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m)) l=m+1;
		else r=m-1;
	}
	cout<<r<<'\n';
}

