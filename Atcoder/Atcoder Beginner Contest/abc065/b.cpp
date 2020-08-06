#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a){
		cin>>x;
		--x;
	}
	int res=0,i=0;
	while(i!=1){
		if(res>n){
			cout<<"-1\n";
			return 0;
		}
		i=a[i];
		++res;
	}
	cout<<res<<'\n';
}


