#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	sort(a.begin(),a.end(),greater<int>());
	cout<<accumulate(a.begin(),a.begin()+k,0)<<'\n';
}


