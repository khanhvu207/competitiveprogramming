/*
	Observation: 
		* Hall's theorem: there exists perfect matchings if |A|<=|B|.
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=3e5+5;
int n,pos[N],q[N],st[N*4],lazy[N*4];

void modify(int id,int tl,int tr,int l,int r,int val){
	if(r<tl||tr<l) return;
	if(l<=tl&&tr<=r){
		lazy[id]+=val;
		return;
	}
	int tm=(tl+tr)>>1;
	modify(id<<1,tl,tm,l,r,val);
	modify(id<<1|1,tm+1,tr,l,r,val);
	st[id]=max(st[id<<1]+lazy[id<<1],st[id<<1|1]+lazy[id<<1|1]);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		pos[x]=i;
	}
	for(int i=1;i<=n;++i) cin>>q[i];
	int res=n;
	cout<<res<<' ';
	modify(1,1,n,1,pos[res],1);
	for(int i=1;i<n;++i){
		modify(1,1,n,1,q[i],-1);
		while(st[1]+lazy[1]<=0){
			--res;
			modify(1,1,n,1,pos[res],1);
		}
		cout<<res<<' ';
	}
}