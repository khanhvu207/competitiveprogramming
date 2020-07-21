#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n);
	ll sum=0;
	for(ll& x:a){
		cin>>x;
		sum+=x;
	}
	ll pf=0;
	ll res=numeric_limits<ll>::max();
	for(int i=0;i<n-1;++i){
		pf+=a[i];
		ll sf=sum-pf;
		res=min(res,abs(pf-sf));
	}
	cout<<res<<'\n';
}
