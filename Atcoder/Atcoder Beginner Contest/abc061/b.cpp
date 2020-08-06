#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int deg[55];
	memset(deg,0,sizeof deg);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	for(int i=1;i<=n;++i)
		cout<<deg[i]<<'\n';
}


