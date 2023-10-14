// prime factorization + linear sieve for speed.
// UPD1: too much optimization :<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
const int MAXSIEVE=31622778;
bitset<MAXSIEVE> notComposite;
vector<int> prime;
map<ll,ll> Map;
ll f[100000];

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

ll fpow(ll a,ll p){
	ll res=1LL;
	while(p){
		if(p&1LL) (res*=a)%=MOD;
		a=(a*a)%MOD;
		p>>=1LL;
	}
	return res;
}

ll computePath(ll u,ll v){
	if(u>v) swap(u,v);
	ll x=v/u,res=1LL,denum=1LL,cntPrime=0LL;
	if(Map.count(x)) return Map[x];
	for(ll p:prime){
		if(p*p*1LL>x) break;
		if(x%p) continue;
		int cnt=0;
		while(x%p==0) ++cnt,x/=p;
		cntPrime+=cnt;
		(denum*=f[cnt])%=MOD;
	}
	if(x>1) ++cntPrime;
	res=f[cntPrime]*fpow(denum,MOD-2)%MOD;
	Map[v/u]=res;
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	notComposite.flip();
	for(int i=2;i*i<MAXSIEVE;++i) if(notComposite.test(i)) for(int j=i*i;j<MAXSIEVE;j+=i) notComposite.reset(j);
	for(int i=2;i<MAXSIEVE;++i) if(notComposite.test(i)) prime.emplace_back(i);
	f[0]=1LL;
	for(ll i=1;i<100000;++i) f[i]=f[i-1]*i%MOD;
	ll n;cin>>n;
	int q;
	cin>>q;
	while(q--){
		ll u,v,res;
		cin>>u>>v;
		if(u>v) swap(u,v);
		if(v%u==0) res=computePath(u,v);
		else{
			ll GCD=__gcd(u,v);
			res=computePath(u,GCD)%MOD*computePath(v,GCD)%MOD;
		}
		cout<<res<<'\n';
	}
}