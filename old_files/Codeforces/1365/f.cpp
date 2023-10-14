// pair{a[i], a[n-i-1]} will be the same if we could transform A into B

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	vector<pair<int,int>> pa,pb;
	for(int& x:a) cin>>x;
	for(int& x:b) cin>>x;
	for(int i=0;i<(n+1)/2;++i){
		pa.emplace_back(a[i],a[n-1-i]);
		pb.emplace_back(b[i],b[n-1-i]);
		if(pa[i].fi>pa[i].se) swap(pa[i].fi,pa[i].se);
		if(pb[i].fi>pb[i].se) swap(pb[i].fi,pb[i].se);
	}
	sort(pa.begin(),pa.end());
	sort(pb.begin(),pb.end());
	if(pa!=pb) cout<<"No\n";
	else cout<<"Yes\n";
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}