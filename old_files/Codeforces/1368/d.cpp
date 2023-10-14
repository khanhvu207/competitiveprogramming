#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	ll res=0;
	vector<ll> a(n),bit(20,0);
	for(ll& x:a){
		cin>>x;
		for(ll j=0;(1ll<<j)<=x;++j)
			bit[j]+=x>>j&1;
	}
	for(int i=0;i<n;++i){
		ll sum=0;
		for(ll j=0;j<20;++j)
			if(bit[j]){
				sum+=1ll<<j;
				bit[j]--;
			}
		res+=sum*sum;
	}
	cout<<res;
}