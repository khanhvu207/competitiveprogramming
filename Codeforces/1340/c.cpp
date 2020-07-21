// wow 0-1 BFS, dopeee XD

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=10005;
const int N=1e6+5;
int n,m;
ll d[MX],g,r,dist[MX][1005];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<m;++i) cin>>d[i];
	cin>>g>>r;
	sort(d,d+m);
	memset(dist,-1,sizeof dist);
	dist[0][0]=0;
	deque<pair<int,int>> dq;
	dq.emplace_front(0,0);
	ll res=1e18;
	while(!dq.empty()){
		int u=dq.front().fi,t=dq.front().se;
		dq.pop_front();
		if(t==0&&n-d[u]<=g){
			ll cost=(g+r)*dist[u][t]+n-d[u];
			res=min(res,cost);
		}
		if(t==g&&dist[u][0]==-1){
			dist[u][0]=dist[u][g]+1;
			dq.emplace_back(u,0);
		}
		if(u){
			ll cost=t+d[u]-d[u-1];
			if(cost<=g&&dist[u-1][cost]==-1){
				dist[u-1][cost]=dist[u][t];
				dq.emplace_front(u-1,cost);
			}
		}
		if(u+1<m){
			ll cost=t+d[u+1]-d[u];
			if(cost<=g&&dist[u+1][cost]==-1){
				dist[u+1][cost]=dist[u][t];
				dq.emplace_front(u+1,cost);
			}
		}
	}
	if(res==1e18) res=-1;
	cout<<res;
}