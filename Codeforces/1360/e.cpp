#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	vector<vector<int>> g(n,vector<int>(m,0));
	if(a*n!=b*m){
		cout<<"NO\n";
		return;
	}
	for(int i=0;i<n;++i) for(int j=0;j<a;++j) g[i][(a*i+j)%m]=1;
	cout<<"YES\n";
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cout<<g[i][j];
		cout<<'\n';
	}
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