#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n),b;
	for(int& x:a) cin>>x;
	b=a;
	sort(a.begin(),a.end());
	int hi_median=a[n/2];
	int lo_median=a[n/2-1];
	for(int i=0;i<n;++i){
		if(b[i]<a[n/2]) cout<<hi_median<<'\n';
		else cout<<lo_median<<'\n';
	}
}
