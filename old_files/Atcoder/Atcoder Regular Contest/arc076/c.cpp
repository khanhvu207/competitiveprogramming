#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,m,mod=1e9+7;
	cin>>n>>m;
	if(abs(n-m)>1){
		return cout<<"0\n",0;
	}
	ll res=1;
	for(ll i=1;i<=n;++i) res=res*i%mod;
	for(ll i=1;i<=m;++i) res=res*i%mod;
	if(n==m) res=res*2LL%mod;
	cout<<res<<'\n';
}

