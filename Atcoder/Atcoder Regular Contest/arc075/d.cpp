#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,a,b,h[N];

bool chk(ll k){
	ll cnt=0;
	for(int i=0;i<n;++i)
		if(h[i]-k*b>0){
			ll x=h[i]-k*b;
			cnt+=x/(a-b)+(x%(a-b)!=0);
		}
	return cnt<=k;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a>>b;
	for(int i=0;i<n;++i) cin>>h[i];
	ll l=1,r=1e16;
	while(l<=r){
		int m=(l+r)>>1;
		if(chk(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<'\n';
}


