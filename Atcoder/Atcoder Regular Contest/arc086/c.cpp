#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> cnt(n+1,0);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[x]++;
	}
	vector<pair<int,int>> v;
	for(int i=1;i<=n;++i)
		if(cnt[i]) v.emplace_back(cnt[i],i);
	sort(v.begin(),v.end(),greater<pair<int,int>>());
	int res=0;
	for(int i=k;i<int(v.size());++i)
		res+=v[i].first;
	cout<<res<<'\n';
}

