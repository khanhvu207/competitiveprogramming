// ...
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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	sort(a.begin(),a.end(),greater<int>());
	ll x=0,y=0;
	for(int i=0;i<n;++i)
		if(i<(n+1)/2) x+=a[i];
		else y+=a[i];
	ll res=x*x+y*y;
	cout<<res;
}