/*
	If G is not a bipartite graph, then the answer is NO.
	We construct bipartite graphs and count odd nodes and even nodes of those graghs.
	And use DP to determine if it's possible to formulate the final answer

	UPD1: I wrote stupid DP >.<
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=5005;
int n,m,n1,n2,n3,cnt;
int color[N],res[N];
vector<int> adj[N],s1[N],s2[N];
bool dp[N][N];

bool bipartite(int u,int p=-1){
	if(color[u]&1) s1[cnt].push_back(u);
	else s2[cnt].push_back(u);
	bool good=true;
	for(int v:adj[u]) if(v!=p){
		if(color[v]==-1){
			color[v]=color[u]^1;
			good&=bipartite(v);
		}
		else if(color[v]==color[u]) good=false;
	}
	return good;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(color,-1,sizeof color);
	cin>>n>>m>>n1>>n2>>n3;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i) if(color[i]==-1){
		++cnt;
		color[i]=0;
		bool ok=bipartite(i);
		if(!ok){
			cout<<"NO\n";
			return 0;
		}
	}
	int even=n2;
	memset(dp,false,sizeof dp);
	dp[0][0]=true;
	for(int j=1;j<=cnt;++j) 
		for(int i=0;i<=even;++i){
			int sz1=s1[j].size(),sz2=s2[j].size();
			if(i-sz1>=0) dp[i][j]|=dp[i-sz1][j-1];
			if(i-sz2>=0) dp[i][j]|=dp[i-sz2][j-1];
		}
	if(!dp[even][cnt]){
		cout<<"NO\n";
		return 0;
	}
	int j=cnt;
	while(even>0){
		int sz1=(int)s1[j].size(),sz2=(int)s2[j].size();
		if(even-sz1>=0&&dp[even-sz1][j-1]){
			for(int u:s1[j]) res[u]=2;
			even-=sz1;
		}
		else{
			for(int u:s2[j]) res[u]=2;
			even-=sz2;
		}
		--j;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		if(res[i]==0){
			if(n1>0) res[i]=1,--n1;
			else res[i]=3,--n3;
		}
		cout<<res[i];
	}
}