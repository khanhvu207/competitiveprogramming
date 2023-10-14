#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	vector<pair<int,int>> s,p;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		s.emplace_back(x,y);
	}
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		p.emplace_back(x,y);
	}
	for(int i=0;i<n;++i){
		int best=1e9,id;
		for(int j=m-1;~j;--j)
			if(abs(s[i].first-p[j].first)+abs(s[i].second-p[j].second)<=best){
				best=abs(s[i].first-p[j].first)+abs(s[i].second-p[j].second);
				id=j;
			}
		cout<<id+1<<'\n';
	}
}


