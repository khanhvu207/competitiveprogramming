#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
int n,m;
char g[1005][1005];
bool vst[1005][1005];
 
void dfs(int x,int y){
	vst[x][y]=true;
	if(x-1>=0&&g[x-1][y]=='#'&&!vst[x-1][y]) dfs(x-1,y);
	if(x+1<n&&g[x+1][y]=='#'&&!vst[x+1][y]) dfs(x+1,y);
	if(y-1>=0&&g[x][y-1]=='#'&&!vst[x][y-1]) dfs(x,y-1);
	if(y+1<m&&g[x][y+1]=='#'&&!vst[x][y+1]) dfs(x,y+1);
}
 
bool check(){
	int row=0,col=0;
	for(int i=0;i<n;++i){
		int cnt=0;
		for(int j=0;j<m;++j) if(g[i][j]=='#'){
			if(j==0||g[i][j-1]=='.') ++cnt;
		}
		if(cnt>1) return false;
		if(cnt==0) ++row;
	}
	for(int i=0;i<m;++i){
		int cnt=0;
		for(int j=0;j<n;++j) if(g[j][i]=='#'){
			if(j==0||g[j-1][i]=='.') ++cnt;
		}
		if(cnt>1) return false;
		if(cnt==0) ++col;
	}
	if(row>col) swap(row,col);
	if(row==0) return col==0;
	return true;
}
 
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>g[i][j];
	if(!check()){
		cout<<-1;
		return 0;
	}
	int res=0;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(g[i][j]=='#'&&!vst[i][j]){
		++res;
		dfs(i,j);
	}
	cout<<res;
}