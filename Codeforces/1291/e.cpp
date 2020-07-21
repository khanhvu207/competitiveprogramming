// It took me ages to get the solution's code's logic...
// So for each connected component, that CC will be a bipartite graph itself
// We assume every nodes lay on the right side initially 

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int inf=333333;
const int N=3e5+5;
int n,k,r[N],p[N],cnt[N][2],diff[N];
string s;
vector<int> g[N];

int getroot(int u){
	if(u==p[u]) return u;
	int par=p[u];
	p[u]=getroot(par);
	diff[u]^=diff[par];
	return p[u];
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k>>s;
	for(int i=0;i<k;++i){
		int m;
		cin>>m;
		while(m--){
			int x;
			cin>>x;
			g[--x].push_back(i);
		}
	}
	for(int i=0;i<k;++i){
		r[i]=1;
		p[i]=i;
		cnt[i][1]=1; //Nodes on the right side by default
	}
	int res=0;
	for(int i=0;i<n;++i){
		int sz=(int)g[i].size();
		if(!sz) goto skip;
		if(sz==1){
			int u=getroot(g[i][0]);
			int t=diff[g[i][0]]^(s[i]=='0')^1;
			res-=min(cnt[u][0],cnt[u][1]);
			cnt[u][t]=inf;
			res+=min(cnt[u][0],cnt[u][1]);
		}
		else{
			int u=getroot(g[i][0]);
			int v=getroot(g[i][1]);
			if(u==v) goto skip;
			int t=diff[g[i][0]]^diff[g[i][1]]^(s[i]=='0');
			if(r[u]<r[v]) swap(u,v);
			r[u]+=r[v];
			p[v]=u;
			diff[v]=t;
			res-=min(cnt[u][0],cnt[u][1]);
			res-=min(cnt[v][0],cnt[v][1]);
			cnt[u][0]+=cnt[v][t];
			cnt[u][1]+=cnt[v][1^t];
			cnt[u][0]=min(cnt[u][0],inf);
			cnt[u][1]=min(cnt[u][1],inf);
			res+=min(cnt[u][0],cnt[u][1]);
		}
		skip:cout<<res<<'\n';
	}
}