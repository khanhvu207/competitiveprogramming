#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	int i=1;
	while(i*2<=n) i*=2;
	cout<<i<<'\n';
}


