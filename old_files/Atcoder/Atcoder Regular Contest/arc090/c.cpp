#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> a(2,vector<int>(n));
	for(int i=0;i<2;++i)
		for(int& x:a[i]) cin>>x;
	int res=0;
	for(int i=0;i<n;++i)
		res=max(res,accumulate(a[0].begin(),a[0].begin()+i,0)+accumulate(a[1].begin()+i+1,a[1].end(),0)+a[0][i]+a[1][i]);
	cout<<res<<'\n';
}

