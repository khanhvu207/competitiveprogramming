#include <bits/stdc++.h>
#define ll int64_t

const int N=1e5+5;
int n;

int main() {
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;
	std::vector<int> a(n),res;
	for(int& x:a) std::cin>>x;
	if(a[0]>1) return std::cout<<-1,0;
	int d=0;
	if(a[0]==1){
		res.push_back(0);
		d=1;
	}
	else{
		while(binary_search(a.begin(),a.end(),d)) ++d;
		res.push_back(d++);
	}
	for(int i=1;i<n;++i){
		if(d+1<a[i]) return std::cout<<-1,0;
		if(a[i]!=a[i-1]) res.push_back(a[i-1]),d=std::max(d,a[i]);
		else{
			while(binary_search(a.begin(),a.end(),d)) ++d;
			res.push_back(d++);
		}
	}
	for(int i:res) std::cout<<i<<' ';
}