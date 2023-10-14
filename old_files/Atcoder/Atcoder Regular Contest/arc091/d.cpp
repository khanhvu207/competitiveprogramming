#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,k;
	cin>>n>>k;
	ll res=0;
	for(ll b=k+1;b<=n;++b){
		ll t=(n-k)/b,total=0;
		for(ll i=1;i<=t+1;++i){
			ll hi=i*b;
			ll lo=k+b*(i-1);
			if(lo==0) lo++;
			if(lo<=hi&&lo<=n) total+=min(n,hi-1)-lo+1;

		}
		//cerr<<b<<' '<<total<<'\n';
		res+=total;
	}
	cout<<res<<'\n';
}


