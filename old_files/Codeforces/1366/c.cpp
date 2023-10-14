#include <bits/stdc++.h>
#define ll int64_t
 
const int MAXSIEVE=5555;
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
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    sieve();
    int q;std::cin>>q;
    std::vector<int> a(q,-1),b(q,-1);
   
    for(int tc=0;tc<q;++tc){
        int x;std::cin>>x;
        int k=-1;
		for(int p:prime){
			if(p*p>x) break;
			if(x%p) continue;
			k=p;
			break;
		}
		if(k==-1) continue;
		a[tc]=1;
		b[tc]=x;
		while(x%k==0) x/=k,a[tc]*=k,b[tc]/=k;
		if(a[tc]==1||b[tc]==1) a[tc]=b[tc]=-1;
	}
 
    for(int i=0;i<q;++i) std::cout<<a[i]<<' ';std::cout<<'\n';
    for(int i=0;i<q;++i) std::cout<<b[i]<<' ';std::cout<<'\n';
}
