#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=2e5+5;
int n,k;
int a[N];

bool check(int X){
	for(int p=0;p<2;++p){
		int j=0;
		for(int i=0;i<n;++i)
			if(((j&1)==p)||a[i]<=X) ++j;
		if(j>=k) return true;
	}
	return false;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>a[i];
	int l=1,r=*max_element(a,a+n)+1;
	while(l<=r){
		int m=(l+r)>>1;
		if(check(m)) r=m-1;
		else l=m+1;
	}
	cout<<l;
}