// Fairly trivial problem F...
// Multisource-BFS

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const int N=1005;
int n,m,k,c[N][N],f[45][N][N];
vector<pair<int,int>> g[45];

void bfs(int color){
	queue<pair<int,int>> Q;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) f[color][i][j]=-1;
	for(auto i:g[color]) Q.push(i),f[color][i.fi][i.se]=0;
	vector<bool> mark(45,false);
	while(!Q.empty()){
		auto u=Q.front();
		Q.pop();
		int col=c[u.fi][u.se];
		if(!mark[col]){
			for(auto nxt:g[col]) 
				if(f[color][nxt.fi][nxt.se]==-1){
					f[color][nxt.fi][nxt.se]=f[color][u.fi][u.se]+1;
					Q.push(nxt);
				}
			mark[col]=true;
		}
		for(int i=0;i<4;++i){
			int x=u.fi+dx[i];
			int y=u.se+dy[i];
			if(x<0||x>=n||y<0||y>=m||f[color][x][y]!=-1) continue;
			f[color][x][y]=f[color][u.fi][u.se]+1;
			Q.push(make_pair(x,y));
		}
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin>>c[i][j];
			--c[i][j];
			g[c[i][j]].push_back(make_pair(i,j));
		}
	for(int i=0;i<k;++i) bfs(i);
	int q;
	cin>>q;
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		--r1,--c1,--r2,--c2;
		int ans=abs(r1-r2)+abs(c1-c2);
		for(int i=0;i<k;++i) ans=min(ans,f[i][r1][c1]+f[i][r2][c2]+1);
		cout<<ans<<'\n';
	}
}