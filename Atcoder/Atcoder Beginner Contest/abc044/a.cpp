#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,k,x,y;
	cin>>n>>k>>x>>y;
	ll cost=min(n,k)*x;
	if(n>k) cost+=(n-k)*y;
	cout<<cost<<'\n';
}


