#include <bits/stdc++.h>
#define ll int64_t

bool intersect(int a,int b,int c,int d){
	return (a<=c&&c<=b)||(c<=a&&a<=d);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	int t;
	std::cin>>t;
	for(int _=t;_--;){
		int n,x,m,res=0;
		std::cin>>n>>x>>m;
		std::vector<bool> ok(m,false);
		std::vector<std::pair<int,int>> seg(m);
		for(int i=0;i<m;++i){
			std::cin>>seg[i].first>>seg[i].second;
			if(intersect(seg[i].first,seg[i].second,x,x)) ok[i]=true;
		}
		for(int i=0;i<m;++i) if(ok[i]){
			int lo=seg[i].first,hi=seg[i].second;
			for(int j=i+1;j<m;++j)
				if(intersect(seg[j-1].first,seg[j-1].second,seg[j].first,seg[j].second)) 
					lo=std::min(lo,seg[j].first),hi=std::max(hi,seg[j].second);
			res=std::max(res,hi-lo+1);
		}
		std::cout<<res<<'\n';
	}
}