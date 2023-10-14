#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=2e5+5;
int n,k,m[MX],c[MX];
vector<int> resSize;
vector<vector<int>> res;


int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>m[i];
	for(int i=1;i<=k;++i) cin>>c[i];
	sort(m,m+n);
	for(int i=n-1;~i;--i){
		if(res.empty()||(int)res.back().size()>=c[m[i]]){
			res.push_back({m[i]});
			resSize.push_back(1);
			continue;
		}
		int pos=upper_bound(resSize.begin(),resSize.end(),c[m[i]],greater<int>())-resSize.begin();
		res[pos].push_back(m[i]);
		++resSize[pos];
	}
	cout<<(int)res.size()<<'\n';
	for(auto& v:res){
		cout<<(int)v.size()<<' ';
		for(int& x:v) cout<<x<<' '; 
		cout<<'\n';
	}
}