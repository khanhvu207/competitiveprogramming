#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	ll res=k;
	for(int i=0;i<n-1;++i)
		res*=(k-1);
	cout<<res<<'\n';
}


