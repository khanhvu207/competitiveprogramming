#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	int sum=accumulate(a.begin(),a.end(),0);
	int t;
	cin>>t;
	while(t--){
		int p,x;
		cin>>p>>x;
		--p;
		cout<<sum-a[p]+x<<'\n';
	}
}


