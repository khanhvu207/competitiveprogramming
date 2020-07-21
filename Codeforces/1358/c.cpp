/*
	Distinct paths yield different sums, but their differences is 1.
	answer = (x1-x2)*(y1-y2)+1
*/
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
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ll res=(x1-x2)*(y1-y2)+1;
		cout<<res<<'\n';
	}
}