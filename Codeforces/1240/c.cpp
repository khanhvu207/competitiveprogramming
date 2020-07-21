#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=5e5+5;
int n,k;
vector<pair<int,ll>> adj[N];
ll dp[2][N];

void dfs(int u,int p=-1){
	vector<ll> vec;
	ll res=0;
	for(auto v:adj[u]) 
		if(v.fi!=p){
			dfs(v.fi,u);
			res+=dp[0][v.fi];
			vec.push_back(max(0LL,dp[1][v.fi]+v.se-dp[0][v.fi]));
		}
	sort(vec.rbegin(),vec.rend());
	dp[0][u]=dp[1][u]=res;
	for(int i=0;i<min(k,(int)vec.size());++i){
		if(i<k-1) dp[1][u]+=vec[i];
		dp[0][u]+=vec[i];
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		adj[i].clear();
		dp[0][i]=dp[1][i]=0;
	}
	for(int i=0;i<n-1;++i){
		int u,v;ll w;
		cin>>u>>v>>w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	dfs(1);
	cout<<max(dp[0][1],dp[1][1])<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}