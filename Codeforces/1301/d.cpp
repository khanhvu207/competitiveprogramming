#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,m,k;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	vector<pair<int,char>> res;
	for(int i=0;i<n-1;++i){
		int go=min(k,m-1);
		if(go) res.push_back(make_pair(go,'R'));
		k-=go;
		if(!k) break;
		go=min(k,m-1);
		if (go) res.push_back(make_pair(go,'L'));
		k-=go;
		if(!k) break;
		res.push_back(make_pair(1,'D'));
		--k;
	}
	if(k){
		int go=min(k,m-1);
		if (go) res.push_back(make_pair(go,'R'));
		int j=go;
		k-=go;
		for(;j>=0;--j){
			go=min(k,n-1);
			if(go) res.push_back(make_pair(go,'U'));
			k-=go;	
			if(j==0) break;
			go=min(k,n-1);
			if(go) res.push_back(make_pair(go,'D'));
			k-=go;	
			if(k) res.push_back(make_pair(1,'L')),--k;
		}
	}
	if(k>0||(int)res.size()>3000){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<(int)res.size()<<'\n';
	for(auto i:res) cout<<i.fi<<' '<<i.se<<'\n';
}