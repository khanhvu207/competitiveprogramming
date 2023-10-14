#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const ll mod=1e9+7;

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) res=res*a%mod;
		a=a*a%mod;
		p>>=1LL;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<ll> cnt(n,0);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[x]++;
	}
	if((n&1)&&(cnt[0]!=1)){
		cout<<0;
		return 0;
	}
	if(n%2==0&&(cnt[0]!=0)){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;++i)
		if(cnt[i]!=2&&cnt[i]!=0){
			cout<<0;
			return 0;
		}
	ll res=fpow(2LL,n/2);
	cout<<res;
}

