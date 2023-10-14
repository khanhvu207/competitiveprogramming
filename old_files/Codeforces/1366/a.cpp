#include <bits/stdc++.h>
#define ll int64_t

int main() {
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	int t;
	std::cin>>t;
	for(int _=t;_--;){
		int a,b,res=0;
		std::cin>>a>>b;
		if(a>b) std::swap(a,b);
		res=std::min(a,b-a);
		b-=2*res;
		a-=res;
		if(a==b) res+=(a+b)/3;
		std::cout<<res<<'\n';
	}
}