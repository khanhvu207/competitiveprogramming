#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll h,w;
	cin>>h>>w;
	ll res=1e18;
	for(ll i=1;i<=h-1;++i){
		ll A=i*w;
		ll B=(h-i)/2LL*w;
		ll C=(h-i-(h-i)/2LL)*w;
		res=min(res,max({A,B,C})-min({A,B,C}));
		B=(h-i)*(w/2LL);
		C=(h-i)*(w-w/2LL);
		res=min(res,max({A,B,C})-min({A,B,C}));
	}
	for(ll i=1;i<=w-1;++i){
		ll A=i*h;
		ll B=(w-i)/2LL*h;
		ll C=(w-i-(w-i)/2LL)*h;
		res=min(res,max({A,B,C})-min({A,B,C}));
		B=(w-i)*(h/2LL);
		C=(w-i)*(h-h/2LL);
		res=min(res,max({A,B,C})-min({A,B,C}));
	}
	cout<<res<<'\n';
}

