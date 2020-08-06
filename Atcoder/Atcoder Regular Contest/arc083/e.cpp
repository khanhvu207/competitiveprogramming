#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF=1e9;
const int N=1005;
const int X=5005;
int n,x[N],b[N];
vector<int> adj[N];

void dfs(int u){
	for(int v:adj[u])
		dfs(v);
	int m=adj[u].size();
	int dp[m+1][X];
	for(int i=0;i<=m;++i)
		for(int j=0;j<X;++j)
			dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=0;i<m;++i){
		int white=x[adj[u][i]];
		int black=b[adj[u][i]];
		for(int j=0;j<X;++j){
			if(j+white<X) dp[i+1][j+white]=min(dp[i+1][j+white],dp[i][j]+black);
			if(j+black<X) dp[i+1][j+black]=min(dp[i+1][j+black],dp[i][j]+white);
		}
	}
	int best=INF;
	for(int i=0;i<=x[u];++i)
		best=min(best,dp[m][i]);
	if(best==INF)
		exit(puts("IMPOSSIBLE\n")*0);
	b[u]=best;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=2;i<=n;++i){
		int v;
		cin>>v;
		adj[v].push_back(i);
	}
	for(int i=1;i<=n;++i)
		cin>>x[i];
	dfs(1);
	cout<<"POSSIBLE\n";
}


