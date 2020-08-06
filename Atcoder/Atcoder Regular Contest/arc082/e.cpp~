#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=998244353;
const int N=1005;
int n,x[N],y[N];

ll fpow(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>x[i]>>y[i];
	ll res=fpow(2,n);
	res=(res-1+mod)%mod;
	res=(res-n+mod)%mod;
	res=(res-n*(n-1)/2+mod)%mod;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j){
			int a=y[j]-y[i];
			int b=x[i]-x[j];
			int c=-a*x[i]-b*y[i];
			ll cnt=2;
			for(int k=0;k<n;++k)
				if(k!=i&&k!=j){
					int t=a*x[k]+b*y[k]+c;
					if(t!=0) continue;
					if(k<j) break;
					cnt++;
				}
			cnt%=mod;
			res=(res-fpow(2,cnt)+mod)%mod;
			res=(res+1)%mod;
			res=(res+cnt)%mod;
			res=(res+cnt*(cnt-1)/2)%mod;
		}
	cout<<res<<'\n';
}


