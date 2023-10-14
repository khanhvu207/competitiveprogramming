#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> cnt[2];
		vector<pair<int,int>> res;
		for(int i=1;i<=n*2;++i){
			int x;cin>>x;
			cnt[x&1].push_back(i);
		}
		while((int)res.size()!=n-1&&(int)cnt[0].size()>=2){
			int x=cnt[0].back(); cnt[0].pop_back();
			int y=cnt[0].back(); cnt[0].pop_back();
			res.emplace_back(x,y);
		}
		while((int)res.size()!=n-1&&(int)cnt[1].size()>=2){
			int x=cnt[1].back(); cnt[1].pop_back();
			int y=cnt[1].back(); cnt[1].pop_back();
			res.emplace_back(x,y);
		}
		for(auto i:res) cout<<i.first<<' '<<i.second<<'\n';
	}
}