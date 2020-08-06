#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=105;
const int INF=1e7;
int n,m,f[N][N],u[N*N],v[N*N],c[N*N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			f[i][j]=INF;
	for(int i=0;i<n;++i)
		f[i][i]=0;
	for(int i=0;i<m;++i){
		cin>>u[i]>>v[i]>>c[i];
		--u[i],--v[i];
		f[u[i]][v[i]]=min(f[u[i]][v[i]],c[i]);
		f[v[i]][u[i]]=min(f[v[i]][u[i]],c[i]);
	}
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int res=m;
	for(int i=0;i<m;++i){
		bool ok=false;
		for(int j=0;j<n;++j)
			if(f[j][u[i]]+c[i]==f[j][v[i]]) ok=true;
		if(ok) --res;
	}
	cout<<res<<'\n';
}


