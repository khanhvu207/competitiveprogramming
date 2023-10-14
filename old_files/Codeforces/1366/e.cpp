#include <bits/stdc++.h>
#define ll int64_t

const int N=2e5+5;
const ll M=998244353;
int n,m,a[N],b[N];
std::map<int,int> pos,act;

int main() {
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>m;
	for(int i=0;i<n;++i) std::cin>>a[i];
	for(int i=0;i<m;++i) std::cin>>b[i];
	for(int i=0;i<n;++i){
		int j=std::lower_bound(b,b+m,a[i])-b;
		while(j!=0&&b[j]>a[i]) --j;
		if(b[j]>a[i]) 
			return std::cout<<0,0;
		if(!act.count(a[i])) act.emplace(a[i],i);
		else act[a[i]]=i;
		a[i]=b[j];
		if(!pos.count(a[i])) pos.emplace(a[i],i);
		else pos[a[i]]=i;
	}
	ll res=1;
	for(int i=0;i<m;++i){
		if(!act.count(b[i])) return std::cout<<0,0;
		if(i&&pos[b[i]]<pos[b[i-1]]) return std::cout<<0,0;
		if(i) (res*=(act[b[i]]-pos[b[i-1]])*1LL)%=M;
	}
	std::cout<<res<<'\n';
}