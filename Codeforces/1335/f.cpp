#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e6+5;
int n,m,color[N],vst[N],cnt[N];
vector<int> adj[N],rev[N];

void dfs(int u,int d,int mod){
	vst[u]=0;
	if(color[u]==0) ++cnt[d%mod];
	for(int v:rev[u]) if(vst[v]==2) dfs(v,d+1,mod);
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
	while(t--){
		cin>>n>>m;
		vector<vector<char>> a(n,vector<char>(m));
		for(int i=0;i<n;++i) for(int j=0;j<m;++j){
			char c;
			cin>>c;
			color[m*i+j]=c-'0';
			adj[m*i+j].clear();
			rev[m*i+j].clear();
		}
		for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>a[i][j];
		for(int i=0;i<n;++i) 
			for(int j=0;j<m;++j){
				vst[i*m+j]=0;
				int x=i,y=j;
				switch(a[i][j]){
					case 'L':
						--y;
						break;
					case 'R':
						++y;
						break;
					case 'U':
						--x;
						break;
					case 'D':
						++x;
						break;
				}
				if(x<0||x>=n||y<0||y>=m) continue;
				int u=i*m+j,v=x*m+y;
				adj[u].push_back(v);
				rev[v].push_back(u);
			}
		int totalCycLen=0;
		vector<pair<int,int>> root;
		for(int i=0;i<n*m;++i) if(!vst[i]){
			int u=i,cyc_len=1;
			vector<int> cyc;
			while(!vst[u]){
				vst[u]=1;
				cyc.push_back(u);
				u=adj[u][0];
			}
			if(vst[u]==1){
				while(cyc.back()!=u) ++cyc_len,vst[cyc.back()]=2,cyc.pop_back();
				totalCycLen+=cyc_len;
				root.push_back({u,cyc_len});
			}
			for(int x:cyc) vst[x]=2;
		}
		int countBlack=0;
		for(auto i:root) if(vst[i.fi]==2){
			for(int j=0;j<i.se;++j) cnt[j]=0;
			dfs(i.fi,0,i.se);
			for(int j=0;j<i.se;++j) countBlack+=cnt[j]>0;
		}
		cout<<totalCycLen<<' '<<countBlack<<'\n';
	}
}