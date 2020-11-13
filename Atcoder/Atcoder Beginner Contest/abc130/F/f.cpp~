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
const double EPS = 1E-12;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=1e5+5;
int n,x[N],y[N];
char d[N];

double f(double t){
	double min_x=1e18;
	double max_x=-1e18;
	double min_y=1e18;
	double max_y=-1e18;
	REP(i,n){
		double newx=x[i];
		double newy=y[i];
		if(d[i]=='L') newx-=t;
		else if(d[i]=='R') newx+=t;
		else if(d[i]=='U') newy+=t;
		else if(d[i]=='D') newy-=t;
		min_x=min(min_x,newx);
		max_x=max(max_x,newx);
		min_y=min(min_y,newy);
		max_y=max(max_y,newy);
	}
	return (max_x-min_x)*(max_y-min_y);	
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n) cin>>x[i]>>y[i]>>d[i];
	double l=0,r=1e9;
	double res=1e18;
	REP(_,200){
		double ml=(r+l*2.0)/3.0;
		double mr=(r*2.0+l)/3.0;
		double resl=f(ml);
		double resr=f(mr);
		res=min(res,min(resl,resr));
		if(resl<resr) r=mr;
		else l=ml;
	}
	cout<<fixed<<setprecision(15)<<res<<'\n';
}

