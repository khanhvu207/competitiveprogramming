#include <bits/stdc++.h>
using namespace std;
#define ll long long

int count(ll x){
	int cnt=0;
	while(x>0) x/=10,++cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;
	cin>>n;
	int res=99;
	for(ll i=1;i*i<=n;++i)
		if(n%i==0){
			ll x=i;
			ll y=n/i;
			res=min(res,max(count(i),count(n/i)));
		}
	cout<<res<<'\n';
}


