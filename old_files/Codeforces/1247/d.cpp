/*
	prime factorization
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,k;
map<ll,int> Map;

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) res*=a;
		a=a*a;
		p>>=1LL;
	}
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	ll res=0LL;
	for(int i=0;i<n;++i){
		ll x,tmp=1LL,y=1LL;
		bool ok=true;
		cin>>x;
		for(ll i=2;i*i<=x;++i) if(x%i==0){
			int cnt=0;
			while(x%i==0) x/=i,++cnt;
			cnt%=k;
			y*=fpow(i,cnt);
			if(cnt==0) continue;
			if(k-cnt>34){
				ok=false;
				continue;
			}
			tmp*=fpow(i,k-cnt);
		}
		if(x>1){
			if(k-1>34) ok=false;
			else tmp*=fpow(x,k-1);
			y*=x;
		}
		if(ok&&Map.count(tmp)) res+=Map[tmp];
		Map[y]++;
		// cerr<<i<<' '<<y<<' '<<tmp<<' '<<res<<' '<<ok<<'\n';
	}
	cout<<res;
}