// ok let's do sqrt decompostion
// udp1: why i kept making silly mistakes >.<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,m,p[N],nxt[N],cnt[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>p[i];
	int k=sqrt(n);
	for(int i=n-1;i>=0;--i)
		if(i+p[i]>=n) nxt[i]=-1,cnt[i]=1;
		else{
			if(i/k==(i+p[i])/k) nxt[i]=nxt[i+p[i]],cnt[i]=1+cnt[i+p[i]];
			else nxt[i]=i+p[i],cnt[i]=1;
		}
	while(m--){
		int t,a,b;
		cin>>t;
		if(t==1){
			cin>>a;
			--a;
			int res=a,steps=0;
			while(nxt[res]!=-1) steps+=cnt[res],res=nxt[res];
			steps+=cnt[res];
			while(res+p[res]<n) res+=p[res];
			cout<<res+1<<' '<<steps<<'\n';
		}
		else{
			cin>>a>>b;
			--a;
			p[a]=b;
			int block=a/k;
			for(int i=min(n-1,k*(block+1)-1);i>=k*block;--i)
				if(i+p[i]>=n) nxt[i]=-1,cnt[i]=1;
				else{
					if(i/k==(i+p[i])/k) nxt[i]=nxt[i+p[i]],cnt[i]=1+cnt[i+p[i]];
					else nxt[i]=i+p[i],cnt[i]=1;
				}
		}
	}
}