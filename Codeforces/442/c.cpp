#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=5e5+5;
int n,pre[N],nxt[N],a[N];
pair<int,int> p[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		pre[i]=i-1;
		nxt[i]=i+1;
		p[i]={a[i],i};
	}	
	sort(p,p+n);
	ll res=0LL;
	for(int i=0;i<n-2;++i){
		int pos=p[i].se;
		if(pre[pos]!=-1&&nxt[pos]!=n) res+=min(a[pre[pos]],a[nxt[pos]]);
		else res+=a[pos];
		nxt[pre[pos]]=nxt[pos];
		pre[nxt[pos]]=pre[pos];
	}
	cout<<res;
}