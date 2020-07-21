#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	vector<int> a;
	cin>>n;
	a.push_back(0);
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		a.push_back(x);
	}
	a.push_back(0);
	int total=0;
	for(int i=1;i<n+2;++i)
		total+=abs(a[i]-a[i-1]);
	for(int i=1;i<n+1;++i){
		int cost=total;
		cost-=abs(a[i]-a[i-1]);
		cost-=abs(a[i+1]-a[i]);
		cost+=abs(a[i+1]-a[i-1]);
		cout<<cost<<'\n';
	}
}

