#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	sort(a.begin(),a.end());
	int res=n,sum=0;
	for(int i=n-1;~i;--i)
		if(sum+a[i]<k) sum+=a[i];
		else res=min(res,i);
	cout<<res<<'\n';
}

