#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int p[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
const int N=555;
const int MX=1<<15;
int n;
ll a[N],val[MX],cnt[MX];

ll get(int mask){
	ll x=1;
	for(int i=0;i<15;++i)
		if(mask>>i&1) x*=1LL*p[i];
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<MX;++i){
		ll k=get(i);
		for(ll j=k;j<=n;j+=k)
			cnt[i]+=a[j];
		for(int u=i;u>0;u=(u-1)&i){
			if(__builtin_popcount(u)&1) val[i]+=cnt[u];
			else val[i]-=cnt[u];
		}
	}
	ll sum=accumulate(a+1,a+n+1,0LL);
	int tmp[10]={53,59,61,67,71,73,79,83,89,97};
	for(int i=0;i<10;++i)
		if(tmp[i]<=n&&a[tmp[i]]<0) sum-=a[tmp[i]];
	ll res=0;
	for(int i=1;i<MX;++i){
		res=max(res,sum-val[i]);
	}
	cout<<res<<'\n';
}


