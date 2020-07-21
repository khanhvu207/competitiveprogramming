#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll> x(n);
	for(ll& y:x) cin>>y;
	ll res=0;
	for(int i=1;i<n;++i)
		res+=min((x[i]-x[i-1])*a,b);
	cout<<res<<'\n';
}

