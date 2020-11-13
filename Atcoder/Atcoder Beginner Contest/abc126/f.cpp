#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) ll((a).size())
#define all(a) (a).begin(), (a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
const ll MOD = 1E9+7;
const ll INF = 1E18;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=1<<17;
bool used[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int m,k;
	cin>>m>>k;
	if((m==1&&k==1)||k>=(1<<m)) exit(puts("-1\n")*0);
	if(!k){
		REP(i,1<<m)
			cout<<i<<' '<<i<<' ';
		cout<<'\n';
		return 0;
	}
	deque<int> res;
	res.pb(k);
	REP(i,1<<m)
		if(i!=k)
			res.push_front(i),res.pb(i);
	res.pb(k);
	for(int x:res) cout<<x<<' ';
	cout<<'\n';
}

