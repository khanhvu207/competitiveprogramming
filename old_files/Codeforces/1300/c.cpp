#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e5+5;
int n,a[N],pre[N],suf[N];

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
		if(i>0) pre[i]=pre[i-1]&(~a[i]);
		else pre[i]=~a[i];
	}
	suf[n-1]=~a[n-1];
	for(int i=n-2;i>=0;--i) suf[i]=suf[i+1]&(~a[i]);
	int pos=0,res=numeric_limits<int>::min();
	for(int i=0;i<n;++i){
		int v=a[i];
		if(i>0) v&=pre[i-1];
		if(i+1<n) v&=suf[i+1];
		if(v>res){
			res=v;
			pos=i;
		}
	}
	cout<<a[pos]<<' ';
	for(int i=0;i<n;++i) if(i!=pos) cout<<a[i]<<' ';
}