/*
	The total hugs function peaks at somewhere in the middle of a month.
	UPD1: why tf did my code get RE?
	UPD2: forgot the case x<di lul ;(
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e6+5;
ll n,x,d[N],t[N],prefix[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>d[i];
		d[i+n+n]=d[i+n]=d[i];
	}
	for(int i=1;i<=3*n;++i){
		prefix[i]=prefix[i-1]+d[i]*(d[i]+1LL)/2LL;
		t[i]=t[i-1]+d[i];
	}
	ll res=0LL;
	for(int i=1,j=1;i<=n;++i){
		while(t[j+1]-t[i-1]<=x) ++j;
		ll k=x-t[j]+t[i-1]+1LL;
		if(k<=0){
			res=max(res,(d[i]*2LL-x+1LL)*x/2LL);
			continue;
		}
		ll y=d[j+1]-k+1LL;
		ll hugs=prefix[j]-prefix[i-1]+k*(k-1LL)/2LL;
		if(k>0){
			hugs+=(d[j+1]+k)*(d[j+1]-k+1LL)/2LL;
			hugs-=(y+1LL)*y/2LL;
		}
		res=max(res,hugs);
	}
	cout<<res;
}