#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,t,res=0;
	cin>>n>>t;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	for(int i=0;i<n;++i)
		res+=(i==n-1||(a[i+1]-a[i]>=t))?t:a[i+1]-a[i];
	cout<<res<<'\n';
}

