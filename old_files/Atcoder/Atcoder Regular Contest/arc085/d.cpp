#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,z,w;
	cin>>n>>z>>w;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	int res=abs(w-a[n-1]);
	if(n>=2) res=max(res,abs(a[n-1]-a[n-2]));
	cout<<res<<'\n';
}


