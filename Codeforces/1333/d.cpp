// Consider '<', those move toward the left end.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,k;
string s;
vector<vector<int>> res;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	cin>>s;
	int sz=s.size(),mx=0;
	while(true){
		res.push_back({});
		for(int i=0;i+1<sz;++i) 
			if(s[i]=='R'&&s[i+1]=='L') ++mx,res.back().push_back(i);
		for(int i:res.back()) swap(s[i],s[i+1]);
		if(res.back().empty()){
			res.pop_back();
			break;
		}
	}
	if(k<(int)res.size()||k>mx){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<(int)res.size();++i){
		while((int)res[i].size()>1&&k>(int)res.size()){
			cout<<1<<' '<<res[i].back()+1<<'\n';
			--k;
			res[i].pop_back();
		}
		cout<<(int)res[i].size()<<' ';
		for(int j:res[i]) cout<<j+1<<' ';
		cout<<'\n';
	}
}