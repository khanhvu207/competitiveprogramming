#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	array<int,3> a;
	for(int i=0;i<3;++i) cin>>a[i];
	sort(a.begin(),a.end());
	cout<<a[0]+a[1]<<'\n';
}


