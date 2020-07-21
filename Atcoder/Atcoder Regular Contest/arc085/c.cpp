#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	int res=(100*(n-m)+1900*m)*(1<<m);
	cout<<res<<'\n';
}

