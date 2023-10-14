#include <bits/stdc++.h>
#define ll int64_t

const int MAXSIEVE=55555;
std::bitset<MAXSIEVE> notComposite;
std::vector<int> prime;

void sieve() {
    notComposite.flip();
    for (int i=2;i*i<MAXSIEVE;++i)
        if (notComposite.test(i))
            for (int j=i*i;j<MAXSIEVE;j+=i) notComposite.reset(j);
    for (int i=2;i<MAXSIEVE;++i)
        if (notComposite.test(i)) prime.emplace_back(i);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	std::ios_base::sync_with_stdio(0);std::cin.tie(0);
	sieve();
	int q;std::cin>>q;
	std::vector<int> a(q,-1),b(q,-1);
	std::vector<int> num(q);
	
	for(int tc=0;tc<q;++tc){
		int x;std::cin>>x;
		num[tc]=x;
		std::vector<int> f;
		for(int i=0;i<(int)prime.size();++i){
			if(prime[i]*prime[i]>x) break;
			if(x%prime[i]) continue;
			int t=1;
			while(x%prime[i]==0) x/=prime[i],t*=prime[i];
			f.push_back(t);
		}
		if(x>1) f.push_back(x);
		if((int)f.size()==1) continue;
		a[tc]=f[0];
		b[tc]=num[tc];
	}

	for(int i=0;i<q;++i)
		if(a[i]!=-1){
			if(std::__gcd(a[i]+b[i],num[i])!=1) std::cerr<<a[i]<<' '<<b[i]<<' '<<num[i]<<'\n';
			assert(std::__gcd(a[i]+b[i],num[i])==1);
		}
	// for(int i=0;i<q;++i) std::cout<<a[i]<<' ';std::cout<<'\n';
	// for(int i=0;i<q;++i) std::cout<<b[i]<<' ';std::cout<<'\n';
}