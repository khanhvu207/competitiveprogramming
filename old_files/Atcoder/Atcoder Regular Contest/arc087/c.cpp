#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	map<int,int> mp;
	int n,res=0;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(auto it:mp)
		if(it.second>it.first) res+=it.second-it.first;
		else if(it.second<it.first) res+=it.second;
	cout<<res<<'\n';
}

