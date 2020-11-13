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
const ll IINF = numeric_limits<ll>::max();
const int INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

const int MX=3;
ll L,A,B,M;

struct Matrix{
	ll A[MX][MX];
	Matrix(){
		memset(A,0,sizeof A);
	}
};

Matrix matmul(Matrix X,Matrix Y){
	Matrix res;
	REP(i,MX)
		REP(k,MX)
			REP(j,MX)
				(res.A[i][j]+=X.A[i][k]%M*Y.A[k][j]%M)%=M;	
	return res;
}

Matrix matpow(Matrix X,ll p){
	Matrix res;
	REP(i,MX) res.A[i][i]=1;
	while(p){
		if(p&1LL) res=matmul(res,X);
		X=matmul(X,X);
		p>>=1LL;
	}	
	return res;
}

ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%M;a=a*a%M;p>>=1LL;} return res;}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>L>>A>>B>>M;
	vector<ll> ub;
	ub.pb(9);
	REP(i,17) ub.pb(ub.back()*10LL+9LL);
	ub.pb(IINF);
	ll k=0,xA=A;
	array<ll,3> base={0,0,1};
	REP(i,sz(ub)){
		if(A>=ub[i]) continue;
		ll cnt=min(L,(ub[i]-A)/B+1);
		Matrix T;
		T.A[0][0]=fpow(10,i+1)%M;
		T.A[0][1]=B%M;
		T.A[0][2]=xA%M;
		T.A[1][0]=0;
		T.A[1][1]=1;
		T.A[1][2]=1;
		T.A[2][0]=0;
		T.A[2][1]=0;
		T.A[2][2]=1;
		T=matpow(T,cnt);
		array<ll,3> tmp;
		tmp[0]=base[0]*T.A[0][0]%M+base[1]*T.A[0][1]%M+base[2]*T.A[0][2]%M;
		tmp[1]=base[1]*T.A[1][1]%M+base[2]*T.A[1][2]%M;
		tmp[2]=base[2]*T.A[2][2]%M;
		tmp[0]%=M;
		tmp[1]%=M;
		tmp[2]%=M;
		base=tmp;
		L-=cnt;
		A+=B*cnt;
		if(!L) break;
	}
	cout<<base[0]<<'\n';
}
// i didn't read the last sentence in constraints, which caused me a lot of time 
// calculate number of terms whose number of digits is D
// for each group of D-digits, we can do matrix multiplication to compute the answer
