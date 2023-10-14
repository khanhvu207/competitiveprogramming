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
	int n,q;
	cin>>n>>q;
	vector<int> dp(n+1,0);
	vector<tuple<int,int,int>> query;
	for(int i=0;i<q;++i){
		int l,r,v;
		cin>>l>>r>>v;
		query.emplace_back(r,-l,v);
	}
	sort(query.begin(),query.end());
	for(auto i:query){
		int l,r,v;
		tie(r,l,v)=i;
		l=-l;
		dp[0]=r;
		for(int j=n-v;j>=0;--j) 
			if(dp[j]>=l) dp[j+v]=max(dp[j+v],dp[j]);
	}
	vector<int> res;
	for(int i=1;i<=n;++i) if(dp[i]) res.push_back(i);
	cout<<(int)res.size()<<'\n';
	for(int i:res) cout<<i<<' ';
}