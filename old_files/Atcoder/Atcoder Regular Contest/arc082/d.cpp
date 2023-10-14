#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,res=0;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	for(int i=0;i<n;++i){
		if(i+1==a[i]) res++,i++;
	}
	cout<<res<<'\n';
}


