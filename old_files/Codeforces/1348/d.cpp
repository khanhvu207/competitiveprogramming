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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> res;
		for(int i=0;(1<<i)<=n;++i){
			res.push_back(1<<i);
			n-=(1<<i);
		}
		if(n) res.push_back(n);
		sort(res.begin(),res.end());
		cout<<(int)res.size()-1<<'\n';
		for(int i=1;i<(int)res.size();++i) cout<<res[i]-res[i-1]<<' ';
		cout<<'\n';
	}
}