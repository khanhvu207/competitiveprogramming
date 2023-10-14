#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll INF=1e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n),pf(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
		pf[i]=a[i];
		if(i) pf[i]+=pf[i-1];
	}
	vector<int> f(n),g(n);
	ll sum=a[0];
	for(int i=1,j=0;i<n;++i){
		ll prevv=abs(2*sum-pf[i]);
		while(j+1<i&&abs(2*(sum+a[j+1])-pf[i])<=prevv) sum+=a[++j],prevv=abs(2*sum-pf[i]);
		f[i]=j;
	}
	sum=a[n-1];
	for(int i=n-2,j=n-1;i>0;--i){
		ll prevv=abs(2*sum-pf[n-1]+pf[i-1]);
		while(j-1>i&&abs(2*(sum+a[j-1])-pf[n-1]+pf[i-1])<=prevv) sum+=a[--j],prevv=abs(2*sum-pf[n-1]+pf[i-1]);
		g[i]=j;
	}
	ll res=INF;
	for(int i=1;i<n-2;++i){
		ll P=pf[f[i]];
		ll Q=pf[i]-P;
		ll S=pf[n-1]-pf[g[i+1]-1];
		ll R=pf[n-1]-P-Q-S;
		res=min(res,abs(min({P,Q,S,R})-max({P,Q,S,R})));
	}
	cout<<res<<'\n';
}


