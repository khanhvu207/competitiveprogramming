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
const ll MOD = 998244353;
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
int lowft[N],highft[N];
ll tot[N];
vector<int> x,y;
vector<pair<int,int>> p;

void lowUpd(int x,int v){
	for(;x<N;x=x|(x+1))
		lowft[x]+=v;
}

int lowGet(int x){
	int res=0;
	for(;x>=0;x=(x&(x+1))-1)
		res+=lowft[x];
	return res;
}

void highUpd(int x,int v){
	for(;x>=0;x=(x&(x+1))-1)
		highft[x]+=v;
}

int highGet(int x){
	int res=0;
	for(;x<N;x=x|(x+1))
		res+=highft[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n){
		int u,v;
		cin>>u>>v;
		p.pb(mp(u,v));
		x.pb(u);
		y.pb(v);
	}	
	sort(p.begin(),p.end());
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	REP(i,n){
		int cur_x=p[i].fi;
		int cur_y=p[i].se;
//		cerr<<"At point: "<<cur_x<<' '<<cur_y<<'\n';
		tot[i]=MOD-1;
		(tot[i]+=fpow(2,n))%=MOD;
		(tot[i]+=MOD-fpow(2,lower_bound(x.begin(),x.end(),cur_x)-x.begin()))%=MOD;
		(tot[i]+=MOD-fpow(2,x.end()-upper_bound(x.begin(),x.end(),cur_x)))%=MOD;
//		cerr<<lower_bound(y.begin(),y.end(),cur_y)-y.begin()<<' '<<y.end()-upper_bound(y.begin(),y.end(),cur_y)<<'\n';
		(tot[i]+=MOD-fpow(2,lower_bound(y.begin(),y.end(),cur_y)-y.begin()))%=MOD;
		(tot[i]+=MOD-fpow(2,y.end()-upper_bound(y.begin(),y.end(),cur_y)))%=MOD;
		// points whose x<cur_x && y<cur_y
		int idy=lower_bound(y.begin(),y.end(),cur_y)-y.begin();
		int lowy=lowGet(idy-1);
		(tot[i]+=fpow(2,lowy))%=MOD;
		lowUpd(idy,1);
		// points whose x<cur_x && y>cur_y
		int highy=highGet(idy+1);
		(tot[i]+=fpow(2,highy))%=MOD;
		highUpd(idy,1);
//		cerr<<lowy<<' '<<highy<<'\n';
	}	
	memset(lowft,0,sizeof lowft);
	memset(highft,0,sizeof highft);
	REPD(i,n){
		int cur_x=p[i].fi;
		int cur_y=p[i].se;
		// points whose x>cur_x && y<cur_y
		int idy=lower_bound(y.begin(),y.end(),cur_y)-y.begin();
		int lowy=lowGet(idy-1);
		(tot[i]+=fpow(2,lowy))%=MOD;
		lowUpd(idy,1);
		// points whose x>cur_x && y>cur_y
		int highy=highGet(idy+1);
		(tot[i]+=fpow(2,highy))%=MOD;
		highUpd(idy,1);
	}
	ll res=0;
	REP(i,n) (res+=tot[i])%=MOD;
	cout<<res<<'\n';
}

