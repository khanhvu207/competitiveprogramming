#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	ll res=numeric_limits<ll>::max();
	for(int i=0,j=k-1;j<n;++i,++j)
		res=min(res,min(abs(a[i]),abs(a[j]))+abs(a[i]-a[j]));
	cout<<res<<'\n';
}

