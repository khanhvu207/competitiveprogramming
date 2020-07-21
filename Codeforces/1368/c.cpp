#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	set<pair<int,int>> res;
	res.emplace(-1,-1);
	for(int i=0;i<n;++i){
		res.emplace(i,i);
		res.emplace(i-1,i);
		res.emplace(i+1,i);
		res.emplace(i,i-1);
		res.emplace(i,i+1);
	}
	res.emplace(n,n);
	cout<<(int)res.size()<<'\n';
	for(auto i:res)
		cout<<i.first<<' '<<i.second<<'\n';
}