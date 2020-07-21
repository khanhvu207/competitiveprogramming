#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e6+5;
int n,q,bit[N];

void upd(int x,int val){
	for(;x>0;x-=x&(-x)) bit[x]+=val;
}

int get(int x){
	int res=0;
	for(;x<=1000000;x+=x&(-x)) res+=bit[x];
	return res;
}

int kth(int k){
	int l=1,r=1000000;
	while(l<=r){
		int m=(l+r)>>1;
		if(get(m)>=k) l=m+1;
		else r=m-1; 
	}
	return r;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		int x;cin>>x;
		upd(x,1);
	}
	int sz=n;
	while(q--){
		int x;cin>>x;
		if(x<0){
			x=-x;
			upd(kth(sz-x+1),-1);
			--sz;
		}
		else upd(x,1),++sz;
	}
	if(sz==0) cout<<0;
	else cout<<kth(1);
}