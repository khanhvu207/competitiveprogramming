#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod=1E9+7;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> x,y;
	ll prevv;
	for(int i=0;i<n;++i){
		ll t;
		cin>>t;
		if(i) x.push_back(t-prevv);
		prevv=t;
	}
	for(int i=0;i<m;++i){
		ll t;
		cin>>t;
		if(i) y.push_back(t-prevv);
		prevv=t;
	}
	ll sumx=0,sumy=0;
	for(int i=0;i<n-1;++i){
		(x[i]=(i?x[i-1]:0)+(i+1LL)*x[i])%=mod;
		(sumx+=x[i])%=mod;
	}
	for(int i=0;i<m-1;++i){
		(y[i]=(i?y[i-1]:0)+(i+1LL)*y[i])%=mod;
		(sumy+=y[i])%=mod;
	}
	ll res=sumx*sumy%mod;
	cout<<res<<'\n';
}


