#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF=numeric_limits<ll>::max();
const int N=1e5+5;
int n,m;
ll a[N],poly[N],cnt[N],sum,res;

void upd(int l,int r,int s){
	poly[l]-=l-s;
	poly[r+1]+=l-s;
	cnt[l]++;
	cnt[r+1]--;
}

ll get(int x){
	return poly[x]+x*cnt[x];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n-1;++i){
		int l=a[i],r=a[i+1];
		if(l<=r){
			if(l+2<=r) upd(l+2,r,1);
			sum+=r-l;
		}
		else{
			int rf=m;
			int lf=1;
			sum+=m-l+r;
			if(l+2<=rf){
				upd(l+2,rf,1);
				upd(1,r,rf-l);
			}
			else{
				if(l==rf) l=2;
				else l=1;
				if(l<=r) upd(l,r,1);
			}
		}
	}
	for(int i=1;i<N;++i){
		poly[i]+=poly[i-1];
		cnt[i]+=cnt[i-1];
	}
	res=INF;
	for(int i=1;i<=m;++i) //?? wtf did i put n here
		res=min(res,sum-get(i));
	cout<<res<<'\n';
}


