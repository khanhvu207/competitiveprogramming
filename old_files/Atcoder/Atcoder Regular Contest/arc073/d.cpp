#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll W;
	cin>>n>>W;
	vector<ll> w(n),v(n);
	vector<ll> t[4];
	for(int i=0;i<n;++i){
		cin>>w[i]>>v[i];
		if(i) w[i]-=w[0];
	}
	ll w0=w[0];
	w[0]=0;
	for(int i=0;i<n;++i)
		t[w[i]].push_back(v[i]);
	for(int i=0;i<4;++i)
		sort(t[i].begin(),t[i].end(),greater<ll>());
	ll sum[4]={0},res=0;
	for(ll i=0;i<=int(t[0].size());++i){
		if(i) sum[0]+=t[0][i-1];
		sum[1]=sum[2]=sum[3]=0;
		for(ll j=0;j<=int(t[1].size());++j){
			if(j) sum[1]+=t[1][j-1];
			sum[2]=sum[3]=0;
			for(ll k=0;k<=int(t[2].size());++k){
				if(k) sum[2]+=t[2][k-1];
				sum[3]=0;
				for(ll g=0;g<=int(t[3].size());++g){
					if(g) sum[3]+=t[3][g-1];
					ll weights=i*w0+j*(w0+1LL)+k*(w0+2LL)+g*(w0+3LL);
					if(weights<=W)
						res=max(res,sum[0]+sum[1]+sum[2]+sum[3]);
				}
			}
		}
	}
	cout<<res<<'\n';
}


