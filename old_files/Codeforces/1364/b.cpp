#include <bits/stdc++.h>
#define ll int64_t

void solve(){
	int n;
	std::cin>>n;
	std::vector<int> a(n);
	for(int& x:a) std::cin>>x;
	int i=1;
	std::vector<int> res;
	while(i<n){
		res.push_back(a[i-1]);
		if(a[i]>a[i-1]) while(i<n&&a[i]>a[i-1]) ++i;
		else while(i<n&&a[i]<a[i-1]) ++i;
	}
	res.push_back(a[n-1]);
	std::cout<<(int)res.size()<<'\n';
	for(int i:res) std::cout<<i<<' ';
	std::cout<<'\n';
}

int main() {
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	int t;
	std::cin>>t;
	while(t--) solve();
}