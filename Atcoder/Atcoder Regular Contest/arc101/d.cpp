#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,a[N];
ll bit[N*3];

void upd(int x){
	for(;x<N*3;x+=x&(-x))
		bit[x]++;
}

ll get(int x){
	ll cnt=0;
	for(;x>0;x-=x&(-x))
		cnt+=bit[x];
	return cnt;
}

bool check(int X){
	memset(bit,0,sizeof bit);
	ll pairs=(n+1LL)*n/2LL,cnt=0;
	int pf=0;
	for(int i=0;i<n;++i){
		pf+=a[i]<X?-1:1;
		cnt+=get(pf+N);
		upd(pf+N);
		if(pf>=0) cnt++;
	}
	return cnt>=(pairs+1LL)/2LL;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	int l=1,r=1e9;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m)) l=m+1;
		else r=m-1;
	}
	cout<<r<<'\n';
}


