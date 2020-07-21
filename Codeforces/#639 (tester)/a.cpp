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
		int n,m;
		cin>>n>>m;
		if(n==1||m==1) cout<<"YES\n";
		else if(n==2&&m==2) cout<<"YES\n";
		else cout<<"NO\n";
	}
}