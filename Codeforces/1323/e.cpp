#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll res=0LL;
		vector<ll> c(n+1),x(n+1),hash(n+1,0);
		for(int i=1;i<=n;++i) cin>>c[i];
		for(int i=1;i<=n;++i) x[i]=rng();
		for(int i=0;i<m;++i){
			int u,v;
			cin>>u>>v;
			hash[v]^=x[u];
		}
		map<ll,ll> Map;
		for(int i=1;i<=n;++i) if(hash[i]) Map[hash[i]]+=c[i];
		for(auto it:Map) res=__gcd(res,it.se);
		cout<<res<<'\n';
	}
}