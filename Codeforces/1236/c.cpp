// unproven, just greedy observation

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
	int n;
	cin>>n;
	vector<vector<int>> g(n);
	bool rev=false;
	int id=0;
	for(int i=n*n;i>=1;--i){
		g[id].push_back(i);
		if((id==0&&rev)||(id==n-1&&!rev)){
			rev^=1;
			continue;
		}
		if(rev) --id;
		else ++id;
	}
	for(int i=0;i<n;++i){
		for(int x:g[i]) cout<<x<<' ';
		cout<<'\n';
	}
}