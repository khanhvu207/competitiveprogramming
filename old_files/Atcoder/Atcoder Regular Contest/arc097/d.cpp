#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,m,a[N],r[N],p[N];

int getroot(int u){
	return p[u]==u?u:p[u]=getroot(p[u]);
}

void joint(int u,int v){
	u=getroot(u);
	v=getroot(v);
	if(u==v) return;
	if(r[u]>r[v]) r[u]+=r[v],p[v]=u;
	else r[v]+=r[u],p[u]=v;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) r[i]=1,p[i]=i;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		joint(x,y);
	}
	int res=0;
	for(int i=1;i<=n;++i)
		if(getroot(i)==getroot(a[i])) res++;
	cout<<res<<'\n';
}


