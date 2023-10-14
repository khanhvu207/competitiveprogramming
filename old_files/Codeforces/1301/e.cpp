#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const char color[4]={'R','G','B','Y'};
const int N=505;
int n,m,q,col[4][N][N],g[N][N],f[N][N][N];
char img[N][N];

bool isAll(int id,int xl,int yl,int xr,int yr){
	int total=col[id][xr][yr];
	if(xl) total-=col[id][xl-1][yr];
	if(yl) total-=col[id][xr][yl-1];
	if(xl&&yl) total+=col[id][xl-1][yl-1];
	return total==(xr-xl+1)*(yr-yl+1);
}

bool calc(int sz,int xl,int yl,int xr,int yr){
	if(sz==0) return true;
	xl+=sz-1;
	yl+=sz-1;
	if(xl>xr||yl>yr) return false;
	int total=f[sz][xr][yr];
	if(xl) total-=f[sz][xl-1][yr];
	if(yl) total-=f[sz][xr][yl-1];
	if(xl&&yl) total+=f[sz][xl-1][yl-1];
	return total>0;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>img[i][j];
	for(int type=0;type<4;++type){
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				col[type][i][j]=(img[i][j]==color[type])+
					(i?col[type][i-1][j]:0)+(j?col[type][i][j-1]:0)-((i&&j)?col[type][i-1][j-1]:0);
	}
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j){
			int nxt=g[i-1][j-1]+2;
			bool ok=true;
			ok&=isAll(0,i-nxt+1,j-nxt+1,i-nxt/2,j-nxt/2);
			ok&=isAll(1,i-nxt+1,j-nxt/2+1,i-nxt/2,j);
			ok&=isAll(2,i-nxt/2+1,j-nxt/2+1,i,j);
			ok&=isAll(3,i-nxt/2+1,j-nxt+1,i,j-nxt/2);
			if(ok) g[i][j]=nxt;
		}
	for(int z=0;z<=250;++z)
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j)
				if(z==0) f[z][i][j]=1;
				else f[z*2][i][j]=(g[i][j]==z*2)+f[z*2][i-1][j]+f[z*2][i][j-1]-f[z*2][i-1][j-1];
	while(q--){
		int xl,yl,xr,yr;
		cin>>xl>>yl>>xr>>yr;
		--xl,--yl,--xr,--yr;
		int l=0,r=500/2;
		while(l<=r){
			int m=(l+r)/2;
			if(calc(m*2,xl,yl,xr,yr)) l=m+1;
			else r=m-1;
		}
		cout<<r*r*4<<'\n';
	}
}