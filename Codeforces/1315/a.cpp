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
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		int res=max(x*b,max((a-x-1)*b,max(y*a,(b-y-1)*a)));
		cout<<res<<'\n';
	}
}