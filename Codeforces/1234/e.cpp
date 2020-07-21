#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m,a[N],cross[N];
vector<int> adj[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<m;++i) cin>>a[i];
	for(int i=0;i<m-1;++i){
		adj[a[i]].push_back(a[i+1]);
		adj[a[i+1]].push_back(a[i]);
		int x=a[i],y=a[i+1];
		if(x>y) swap(x,y);
		if(x+1<=y-1) ++cross[x+1],--cross[y];
	}
	for(int i=1;i<N;++i) cross[i]+=cross[i-1];
	ll res=0;
	for(int i=0;i<m-1;++i) res+=abs(a[i]-a[i+1]);
	cout<<res<<' ';
	ll p1=res;
	for(int i=2;i<=n;++i){
		res=p1;
		res-=cross[i];
		for(int v:adj[i])
			if(v!=i){
				res-=abs(i-v);
				res+=v>i?v-1:v;
			}
		cout<<res<<' ';
	}
}