#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int res=0;
	for(int i=0;i<=a;++i){
		int tb=b-i*2;
		if(tb<0) continue;
		for(int j=0;j<=tb;++j) if(c-j*2>=0) res=max(res,3*(i+j));
	}
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