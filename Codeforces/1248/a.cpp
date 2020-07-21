// UPD1: overflow :<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int n,m;
	cin>>n;
	ll o1=0,e1=0,o2=0,e2=0;
	for(int i=0;i<n;++i){
		int x;cin>>x;
		if(x&1) ++o1;
		else ++e1;
	}
	cin>>m;
	for(int i=0;i<m;++i){
		int x;cin>>x;
		if(x&1) ++o2;
		else ++e2;
	}
	ll res=o1*o2+e1*e2;
	cout<<res<<'\n';
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