// Asking two questions is enough?

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> g(n+1);
		for(int i=0;i<n-1;++i){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int k1,k2;
		cin>>k1;
		bool marked_a[n+1]={false};
		for(int i=0;i<k1;++i){
			int x;
			cin>>x;
			marked_a[x]=true;
		}
		int b;
		bool marked_b[n+1]={false};
		cin>>k2;
		for(int i=0;i<k2;++i){
			cin>>b;
			marked_b[b]=true;
		}
		int a;
		cout<<"B "<<b<<endl;
		cin>>a;
		if(marked_a[a]){
			cout<<"C "<<a<<endl;
			continue;
		}
		int c;
		bool flag=false;
		function<void(int,int)> dfs=[&](int u,int p){
			if(flag) return;
			if(marked_a[u]){c=u,flag=true; return;}
			for(int v:g[u]) if(v!=p) dfs(v,u);
		};
		dfs(a,-1);
		cout<<"A "<<c<<endl;
		cin>>b;
		if(marked_b[b]) cout<<"C "<<c<<endl;
		else cout<<"C "<<-1<<endl;
	}
}