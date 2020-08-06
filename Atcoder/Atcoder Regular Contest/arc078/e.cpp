#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool ask(ll x){
	cout<<"? "<<x<<'\n';
	cout<<flush;
	char r;
	cin>>r;
	return r=='Y'?true:false;
}

void ans(ll x){
	cout<<"! "<<x<<'\n';
	cout<<flush;
}

const ll MX=1e10;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll res=0,lim=10,len=1;
	while(lim<=MX&&ask(lim)) lim*=10,++len;
	if(lim>MX){
		ll k=MX-1;
		res=lim/10;
		while(k>0&&ask(k))
			k/=10,res/=10;
		ans(res);
		return 0;
	}
	for(int i=0;i<len-1;++i){
		int l=!i?1:0,r=9;
		while(l<=r){
			int m=(l+r)/2;
			ll x=res*10+m;
			if(ask(x)) l=m+1;
			else r=m-1;
		}
		res=res*10+r;
	}
	for(int i=!res?1:0;i<=9;++i)
		if(ask(res*100+i*10+1)){
			ans(res*10+i);
			return 0;
		}
}


