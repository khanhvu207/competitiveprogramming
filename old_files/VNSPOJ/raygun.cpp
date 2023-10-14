// mobius transformation

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,m,mobius[1000005],p[1000005];

void precal(int maxn){
	mobius[1]=1;
	for(int i=2;i<=maxn;++i){
		if(!p[i]) for(int j=i;j<=maxn;j+=i) if(!p[j]) p[j]=i;
		mobius[i]=[](int x){
			int cnt=0;
			while(x>1){
				int k=0,d=p[x];
				while(x%d==0){
					x/=d;
					++k;
					if(k>1) return 0;
				}
				++cnt;
			}
			return (cnt&1)?-1:1;
		}(i);
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	precal(1000000);
	int t;
	cin>>t;
	for(int c=1;c<=t;++c){
		cin>>n>>m;
		ll res=0LL;
		for(ll i=1;i<=min(n,m);++i) 
			res+=mobius[i]*1LL*(n/i)*(m/i);
		res+=(n>0);
		res+=(m>0);
		cout<<"Case "<<c<<": "<<res<<'\n';
	}
}