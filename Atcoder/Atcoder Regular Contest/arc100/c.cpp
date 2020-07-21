#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> v;
	for(int i=1;i<=n;++i){
		ll x;
		cin>>x;
		v.push_back(x-i);
	}
	sort(v.begin(),v.end());
	ll median=v[n/2],sum=0;
	for(ll x:v)
		sum+=abs(x-median);
	cout<<sum<<'\n';
}

