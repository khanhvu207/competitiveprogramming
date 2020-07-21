#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAXSIEVE=31622778;
bitset<MAXSIEVE> notComposite;
vector<int> prime;

ll countDivisors(ll x){
	int res=1LL;
	for(int p:prime){
		if(p*p*1LL>x) break;
		int cnt=1LL;
		while(x%p==0) ++cnt,x/=p;
		res*=cnt;
	}
	if(x>1) res*=2LL;
	return res;
}

void sieve(){
	notComposite.flip();
	for(int i=2;i*i<MAXSIEVE;++i) if(notComposite.test(i)) for(int j=i*i;j<MAXSIEVE;j+=i) notComposite.reset(j);
	for(int i=2;i<MAXSIEVE;++i) if(notComposite.test(i)) prime.emplace_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	sieve();
}
