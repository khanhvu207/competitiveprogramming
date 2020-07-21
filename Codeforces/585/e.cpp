/*
	Mobius transformation
	Kept getting TLEs :(((
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e7+5;
const int MX=5e5+5;
const ll MOD=1e9+7;

vector<int> mob;
int n,a[MX];
ll pow2[MX],cnt[N],f[N];

void precal(int maxn){
	pow2[0]=1LL;
	for(int i=1;i<=n;++i) pow2[i]=pow2[i-1]*2LL%MOD;
	mob.resize(maxn+1,2);
	mob[1]=1;
	for(ll i=2;i<=maxn;++i) if(mob[i]==2){
		// i is prime!
		if(i*i<=maxn) for(ll j=i*i;j<=maxn;j+=i*i) mob[j]=0;
		for(ll j=i;j<=maxn;j+=i){
			if(mob[j]==2) mob[j]=1;
			mob[j]=-mob[j];
		}
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	int m=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		++cnt[a[i]];
		m=max(m,a[i]);
	}
	precal(m+1);
	for(int i=1;i<=m;++i) for(int j=i*2;j<=m;j+=i) cnt[i]+=cnt[j];
	for(int i=1;i<=m;++i) cnt[i]=(pow2[cnt[i]]-1LL+MOD)%MOD;
	ll totalGCD1=0LL;
	for(int i=1;i<=m;++i) (totalGCD1+=mob[i]*cnt[i]+MOD)%=MOD;
	for(int i=2;i<=m;++i) if(mob[i]!=0){
		for(int j=i;j<=m;j+=i) (f[j]+=-1LL*mob[i]*cnt[i]+MOD)%=MOD;
	}
	ll res=0LL;
	for(int i=0;i<n;++i) (res+=pow2[n]-1LL-totalGCD1-f[a[i]]+3LL*MOD)%=MOD;
	cout<<res;
}