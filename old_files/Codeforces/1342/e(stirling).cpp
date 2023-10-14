// stirling number of 2nd kind approach
// let's assume each row has 1 rook, then there are k empty columns
// the answer is the number of n rooks placement to n-k columns
// where each column has at least 1 rook
// 
// We choose nCk(n,k) empty columns,
// and multiply with the number of ways to choose n rows for n-k non-empty columns
// * The number of ways to choose n rows for n-k non-empty columns:
// 		S(n,n-k) * (n-k)!,	where S is Stirling number of 2nd kind.
// * Answer = 2 * nCk(n,k) * S(n,n-k) * (n-k)!

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
const int MX=2e5+5;
ll n,k,f[MX];

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) res=res*a%MOD;
		a=a*a%MOD;
		p>>=1LL;
	}
	return res;
}

ll nCk(ll N,ll K){
	ll res=f[N];
	res=res*fpow(f[N-K],MOD-2LL)%MOD;
	res=res*fpow(f[K],MOD-2LL)%MOD;
	return res%MOD;
}

ll stirling(ll N,ll K){ // O(K * log(N)^2) 
	ll res=0LL;
	for(int j=0;j<=K;++j){
		ll tmp=nCk(K,j)*fpow(j,N)%MOD;
		if((K-j)&1) tmp=-tmp;
		res+=tmp;
		if(res>=MOD) res-=MOD;
		if(res<0) res+=MOD;
	}
	res=res*fpow(f[K],MOD-2LL)%MOD;
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	if(k>=n){
		cout<<0;
		return 0;
	}
	f[0]=1LL;
	for(int i=1;i<MX;++i) f[i]=f[i-1]*i*1LL%MOD;
	ll res=nCk(n,k)*stirling(n,n-k)%MOD;
	res=res*f[n-k]%MOD;
	if(k) res=res*2LL%MOD;
	cout<<res;
}