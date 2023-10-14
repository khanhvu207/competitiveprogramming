/*
	let a = (a1, k1*a1, k2*a1, ..), then every x satisfy any permutation of a.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll M=998244353;
const int N=5e5+5;
ll f[N];

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) res=res*a%M;
		a=a*a%M;
		p>>=1LL;
	}
	return res;
}

ll nCk(ll n,ll k){
	ll res=f[n];
	res=res*fpow(f[k],M-2LL)%M;
	res=res*fpow(f[n-k],M-2LL)%M;
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	f[0]=1LL;
	for(ll i=1;i<N;++i) f[i]=f[i-1]*i%M;
	int n,k;
	cin>>n>>k;
	ll res=0LL;
	for(int i=1;i<=n;++i){
		ll cnt=n/i;
		if(k>cnt) continue;
		(res+=nCk(n/i-1LL,k-1LL))%=M;
	}
	cout<<res;
}