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

ll l,r;
ll dp[65][2][2][2];

ll go(ll i,bool okl,bool okr,bool valid,ll A,ll B){
	if(i==-1) return valid;
	ll& res=dp[i][okl][okr][valid];
	if(~res) return res;
	res=0;
	bool bitl=getbit(l,i);
	bool bitr=getbit(r,i);
	//case: 0/0
	if(!bitl||(bitl&&okl))
		res=go(i-1,okl,okr||bitr,valid,A,B);
	//case: (0/1) and (1/1)
	REP(a,2){
		int b=1;
		if(!bitr&&!okr&&b) continue;
		if(bitl&&!okl&&!a) continue;
		if(!valid&&!a) continue;
		bool newokl=okl||(a==1&&!bitl);
		bool newvalid=valid||(a==1);
		int newA=A;
		int newB=B;
		if(a) newA+=1LL<<i;
		if(b) newB+=1LL<<i;
		(res+=go(i-1,newokl,okr,newvalid,newA,newB))%=MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>l>>r;
	memset(dp,-1,sizeof dp);
	cout<<go(60,false,false,false,0,0)<<'\n';
}
