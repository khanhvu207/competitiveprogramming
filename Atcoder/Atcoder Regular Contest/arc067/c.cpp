#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod=1e9+7;

bool isprime(int x){
	if(x<2) return false;
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	ll res=1;
	for(int i=2;i<=n;++i)
		if(isprime(i)){
			ll t=n,cnt=0;
			while(t>0) cnt+=t/i,t/=i;
			res=res*(cnt+1ll)%mod;
		}
	cout<<res<<'\n';
}

