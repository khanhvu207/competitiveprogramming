#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n,m;
ll a[5005],b[5005][205],sum[5005][5005];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n-1;++i) cin>>a[i];
	for(int i=1;i<n-1;++i) a[i]+=a[i-1];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j) 
			cin>>b[i][j];
	for(int i=0;i<m;++i){
		vector<int> dq,l(n),r(n);
		for(int j=0;j<n;++j){
			while(!dq.empty()&&b[j][i]>b[dq.back()][i]) dq.pop_back();
			l[j]=!dq.empty()?dq.back()+1:0;
			dq.push_back(j);
		}
		dq.clear();
		for(int j=n-1;~j;--j){
			while(!dq.empty()&&b[j][i]>b[dq.back()][i]) dq.pop_back();
			r[j]=!dq.empty()?dq.back()-1:n-1;
			dq.push_back(j);
		}
		for(int j=0;j<n;++j){
			sum[l[j]][j]+=b[j][i];
			sum[j+1][j]-=b[j][i];
			sum[l[j]][r[j]+1]-=b[j][i];
			sum[j+1][r[j]+1]+=b[j][i];
		}
	}
	ll res=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			sum[i][j]+=(i?sum[i-1][j]:0)+(j?sum[i][j-1]:0)-((i&&j)?sum[i-1][j-1]:0);
			ll dist=0;
			if(i>j) continue;
			if(j) dist+=a[j-1];
			if(i) dist-=a[i-1];
			res=max(res,-dist+sum[i][j]);
		}
	cout<<res<<'\n';
}

