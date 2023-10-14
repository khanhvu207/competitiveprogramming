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
		vector<int> b(n);
		for(int& x:a) cin>>x;
		for(int& x:b) cin>>x;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i:a) cout<<i<<' ';cout<<'\n';
		for(int i:b) cout<<i<<' ';cout<<'\n';
	}
}