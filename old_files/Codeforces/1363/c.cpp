// ...
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e3+5;
int n,x,deg[N];

void solve(){
	cin>>n>>x;
	memset(deg,0,sizeof deg);
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		++deg[u],++deg[v];
	}
	cout<<(n%2==0||deg[x]<=1?"Ayush\n":"Ashish\n");
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}