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
 
const int MX=3005;
int p,a[MX];
ll mod;
ll num[MX];
 
using poly=vector<ll>;
vector<poly> pf,sf;
 
poly polymul(const poly &left,const poly &right){
	poly res(MX,0);
	REP(i,sz(left))
		REP(j,sz(right))
			if (i+j<MX) (res[i+j]+=left[i]*right[j]%p)%=p;
	return res;
}
 
poly polyplus(const poly &left,const poly &right){
	poly res(MX,0);
	REP(i,p){
		if(i<sz(left)) (res[i]+=left[i])%=p;
		if(i<sz(right)) (res[i]+=right[i])%=p;
	}
	return res;
}
 
poly polydiv(poly P,int x){
	int k=sz(P);
	poly res(k-1,0);
	FORD(i,k-1,1){
		(P[i-1]+=x*P[i]%p)%=p;
		res[i-1]=P[i];
	}
	return res;
}

ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%mod;a=a*a%mod;p>>=1LL;} return res;}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>p;
  	mod=p;
	REP(i,p) cin>>a[i];
	poly init(MX,0);
	init[1]=1;
	FOR(i,1,p-1){
		poly mul={p-i,1};
		init=polymul(init,mul);
	}
	REP(i,p){
		num[i]=1;
		REP(j,p)
			if(i!=j) num[i]=num[i]*(i-j+p)%p;
	}
	poly res(MX,0);
	REP(i,p){
		if(!a[i]) continue;
		poly s=polydiv(init,i);
		poly tmp={fpow(num[i],p-2)};
		s=polymul(s,tmp);
		res=polyplus(res,s);
	}
	REP(i,p) cout<<res[i]<<' ';
	cout<<'\n';

}
