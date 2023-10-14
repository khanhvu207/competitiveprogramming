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
int n,q,res[N];
vector<pair<int,pair<int,int>>> b;
set<pair<int,int>> p;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	REP(i,n){
		int s,t,x;
		cin>>s>>t>>x;
		b.eb(x,mp(s,t));
	}	
	sort(all(b));
	REP(i,q){
		int d;
		cin>>d;
		p.emplace(d,i);
	}	
	memset(res,-1,sizeof res);
	for(auto i:b){
		int x=i.fi;
		int s=i.se.fi;
		int t=i.se.se-1;
		auto it=p.lower_bound(mp(s-x,-1));
		vector<pair<int,int>> tmp;
		while(it!=p.end()&&s<=it->first+x&&it->first+x<=t){
			res[it->second]=x;
			tmp.eb(*it);
			it++;
		}	
		for(auto j:tmp) p.erase(j);
	}
	REP(i,q) cout<<res[i]<<'\n';
}

