#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	sort(a.begin(),a.end());
	cout<<a[n-1]-a[0]<<'\n';
}


