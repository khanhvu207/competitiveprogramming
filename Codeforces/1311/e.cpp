// With n nodes, 
//	the tree with maximum D is a linear tree, (n * (n + 1) / 2)
//	and the tree with minimum D is a complete binary tree (2 + 4 + ..)

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
		int n,d;
		cin>>n>>d;
		int ud=n*(n-1)/2,ld=0;
		for(int i=1,h=0;i<=n;++i){
			if(!(i&(i-1))) ++h;
			ld+=h-1;
		}
		if(!(ld<=d&&d<=ud)){
			cout<<"NO\n";
			continue;
		}
		vector<int> p(n);
		vector<int> child(n,1);
		vector<int> depth(n,0);
		vector<bool> bad(n,false);
		iota(p.begin(),p.end(),-1);
		iota(depth.begin(),depth.end(),0);
		child[n-1]=0;
		int sum=ud;	
		while(sum>d){
			int v=-1,u=-1;
			for(int i=0;i<n;++i) if(!bad[i]&&child[i]==0&&(v==-1||depth[v]>depth[i])) v=i;
			for(int i=0;i<n;++i) if((child[i]<2)&&depth[i]<depth[v]-1&&(u==-1||depth[u]<depth[i])) u=i;
			if(u==-1){
				bad[v]=true;
				continue;
			}
			--child[p[v]];
			--depth[v];
			++child[u];
			p[v]=u;
			--sum;
		}
		cout<<"YES\n";
		for(int i=1;i<n;++i) cout<<p[i]+1<<' ';
		cout<<'\n';
	}
}