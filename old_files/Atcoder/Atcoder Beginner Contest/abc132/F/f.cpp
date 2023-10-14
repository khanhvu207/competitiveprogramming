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

const int N=105;
const int MX=1e9;
int n,k;
ll small[N][32000],big[N][32000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	if(n==1) exit(puts("1")*0);
	int base=sqrt(n)+1;
	small[0][1]=1;
	REP(i,k){
		FOR(j,1,base-1) (small[i][j]+=small[i][j-1])%=MOD;
		FORD(j,base-2,1) (big[i][j]+=big[i][j+1])%=MOD;
		FOR(j,1,base-1){
			if(n/j==j) continue;
			big[i+1][j]=small[i][j]*(n/j-n/(j+1))%MOD;
		}
		FOR(j,1,base-1) small[i+1][j]=(big[i][j]+small[i][base-1])%MOD;
	}	
	ll res=0;
	REP(i,base) (res+=small[k][i]+big[k][i])%=MOD;
	cout<<res<<'\n';
}

