// exclusion-inclusion approach
// let's assume each row has 1 rook, then there are k empty columns
// the answer is the number of n rooks placement to n-k columns
// where each column has at least 1 rook

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
	ll res=0LL;
	for(int i=0;i<=n-k;++i){
		ll tmp=nCk(n-k,i)*fpow(n-k-i,n)%MOD;
		if(i&1) tmp=-tmp;
		res+=tmp;
		if(res>=MOD) res-=MOD;
		if(res<0) res+=MOD;
	}
	res=res*nCk(n,n-k)%MOD;
	if(k) res=res*2LL%MOD;
	cout<<res;
}