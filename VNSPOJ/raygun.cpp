// mobius transformation

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,m,mobius[1000005],p[1000005];

void precal(int maxn){
	// for(int i=2;i<=sqrt(maxn);++i)
	// 	if(!chk[i]) for(int j=i;j<=maxn/i;++j) chk[i*j]=true;
	// for(int i=2;i<=maxn;++i) if(!chk[i]) p.push_back(i);
	// mobius[1]=1;
	// for(int i=2;i<=maxn;++i){
	// 	bool square=false;
	// 	int cnt=0,x=i;
	// 	for(int j=0;j<(int)p.size()&&p[j]<=sqrt(x)&&!square;++j)
	// 		if(x%p[j]==0){
	// 			square|=x%(p[j]*p[j])==0;
	// 			while(x%p[j]==0) x/=p[j];
	// 			++cnt;
	// 		}
	// 	cnt+=x>1;
	// 	if(square) mobius[i]=0;
	// 	else mobius[i]=(cnt&1)?-1:1;
	// }
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