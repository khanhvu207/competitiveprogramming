#include <bits/stdc++.h>
#define ll int64_t

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	int t;
	std::cin>>t;
	while(t--){
		int n,x;
		std::cin>>n>>x;
		int prevv=-1,sum=0,res=-1;
		for(int i=0;i<n;++i){
			int a;std::cin>>a;
			a%=x;
			sum+=a;
			if(sum%x) res=std::max(res,i+1);
			else if(prevv!=-1) res=std::max(res,i-prevv);
			if(prevv==-1&&(sum%x)) prevv=i;
		}
		std::cout<<res<<'\n';
	}
}