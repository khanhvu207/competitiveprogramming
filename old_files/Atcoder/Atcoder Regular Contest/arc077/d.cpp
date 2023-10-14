#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod=1E9+7;
const int N=1e5+5;
int n;
ll fact[N];

ll fpow(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1LL;
	}
	return res;
}

ll nCk(ll N,ll K){
	ll res=fact[N];
	res=res*fpow(fact[K],mod-2LL)%mod;
	res=res*fpow(fact[N-K],mod-2LL)%mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	fact[0]=1;
	for(ll i=1;i<N;++i)
		fact[i]=fact[i-1]*i%mod;
	cin>>n;
	vector<int> a(n+1),cnt(n+5,0);
	int dup;
	for(int& x:a){
		cin>>x;
		cnt[x]++;
		if(cnt[x]==2)
			dup=x;
	}
	int l=0,r=n;
	while(a[l]!=dup) l++;
	while(a[r]!=dup) r--;
	int k=l+n-r;
	cout<<n<<'\n';
	for(int i=2;i<=n+1;++i){
		ll res=0;
		(res+=nCk(n+1,i))%=mod;
		if(i-1<=k) 
			(res=res-nCk(k,i-1)+mod)%=mod;
		cout<<res<<'\n';
	}
}


