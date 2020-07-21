#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll res=1e18;
	cin>>n;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	ll sum=0,cnt=0;
	for(int i=0;i<n;++i){
		sum+=a[i];
		if(i%2==0&&sum>=0){
			cnt+=sum+1;
			sum=-1;
		}
		else if((i&1)&&sum<=0){
			cnt+=1-sum;
			sum=1;
		}
	}
	res=min(res,cnt);
	sum=cnt=0;
	for(int i=0;i<n;++i){
		sum+=a[i];
		if(i%2==0&&sum<=0){
			cnt+=1-sum;
			sum=1;
		}
		else if((i&1)&&sum>=0){
			cnt+=sum+1;
			sum=-1;
		}
	}
	res=min(res,cnt);
	cout<<res<<'\n';
}

