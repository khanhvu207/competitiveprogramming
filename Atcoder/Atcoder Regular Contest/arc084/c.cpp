#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n),b(n),c(n);
	for(int& x:a) cin>>x;
	for(int& x:b) cin>>x;
	for(int& x:c) cin>>x;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	vector<ll> way(n,0);
	for(int i=0,j=-1;i<n;++i){
		while(j+1<n&&a[j+1]<b[i]) j++;
		way[i]=j+1;
	}
	ll sum=0,res=0;
	for(int i=0,j=-1;i<n;++i){
		while(j+1<n&&b[j+1]<c[i]) sum+=way[++j];
		res+=sum;
	}
	cout<<res<<'\n';
}

