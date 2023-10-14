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
		vector<int> a(n);
		for(int& x:a) cin>>x;
		int mx=a[0],res=0;
		for(int i=1;i<n;++i){
			if(mx>a[i]) res|=mx-a[i];
			mx=max(mx,a[i]);
		}
		if(res!=0) res=32-__builtin_clz(res);
		cout<<res<<'\n';
	}
}