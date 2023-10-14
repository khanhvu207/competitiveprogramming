/*
	We mark those cell with 4 opposite color adjacent cells with number 0, otherwise, number 1.
	Calculate the shortest distance from cell 0s to any cell 1.
	Multisource BFS? 128MB might be enough
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1005;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
int n,m,t,d[N][N];
array<bitset<1005>,1005> a;
queue<pair<short,short>> Q;

bool chk(int x,int y){
	for(int i=0;i<4;++i){
		int X=x+dx[i];
		int Y=y+dy[i];
		if(X>=0&&X<n&&Y>=0&&Y<m&&a[X].test(Y)==a[x].test(y)) return true;
	}
	return false;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>t;
	for(int i=0;i<n;++i){
		a[i].reset();
		for(int j=0;j<m;++j){
			char c;
			cin>>c;
			d[i][j]=-1;
			if(c=='1') a[i].set(j);
		}
	}
	for(int i=0;i<n;++i) 
		for(int j=0;j<m;++j)
			if(chk(i,j))
				Q.emplace(i,j),d[i][j]=0;
	while(!Q.empty()){
		pair<short,short> u=Q.front();
		Q.pop();
		for(int i=0;i<4;++i){
			int x=u.fi+dx[i];
			int y=u.se+dy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&d[x][y]==-1){
				d[x][y]=d[u.fi][u.se]+1;
				Q.emplace(x,y);
			}
		}
	}
	while(t--){
		int x,y;
		ll p,res,init;
		cin>>x>>y>>p;
		--x,--y;
		init=a[x].test(y);
		if(d[x][y]==-1) res=init;
		else if(d[x][y]==0) res=init^(p&1);
		else{
			if(p<=d[x][y]) res=init;
			else res=init^((p-d[x][y])&1);
		}
		cout<<res<<'\n';
	}
}
