#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll c,res=0;
	cin>>n>>c;
	vector<ll> x(n),v(n);
	for(int i=0;i<n;++i) 
		cin>>x[i]>>v[i];
	vector<ll> pf(n),pmx(n);
	for(int i=0;i<n;++i){
		pf[i]=v[i]-x[i];
		if(i) pf[i]+=pf[i-1]+x[i-1];
		if(i) pmx[i]=max(pmx[i-1],pf[i]);
		else pmx[i]=pf[i];
	}	
	vector<ll> sf(n),smx(n);
	for(int i=n-1;~i;--i){
		sf[i]=v[i]-(c-x[i]);
		if(i<n-1) sf[i]+=sf[i+1]+(c-x[i+1]);
		if(i<n-1) smx[i]=max(smx[i+1],sf[i]);
		else smx[i]=sf[i];
	}
	res=max(pmx[n-1],smx[0]);
	for(int i=0;i<n-1;++i) res=max(res,pf[i]+smx[i+1]-x[i]);
	for(int i=n-1;i>0;--i) res=max(res,sf[i]+pmx[i-1]-(c-x[i]));
	if(res<0) res=0;
	cout<<res<<'\n';
}


