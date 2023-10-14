#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	deque<int> v;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(i&1) v.push_front(x);
		else v.push_back(x);
	}
	if(n&1) reverse(v.begin(),v.end());
	for(int x:v) cout<<x<<' ';
	cout<<'\n';
}

