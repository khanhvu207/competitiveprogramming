#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	vector<tuple<int,int,bool>> v;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		v.emplace_back(x,y,0);
	}
	for(int i=0;i<n;++i){
		int x,y;
		cin>>x>>y;
		v.emplace_back(x,y,1);
	}
	sort(v.begin(),v.end());
	set<int> s;
	int res=0;
	for(int i=0;i<2*n;++i)
		if(!get<2>(v[i])) s.insert(get<1>(v[i]));
		else{
			int y=get<1>(v[i]);
			auto it=s.lower_bound(y);
			if(it==s.begin()) continue;
			res++;
			it--;
			s.erase(*it);
		}
	cout<<res<<'\n';
}

