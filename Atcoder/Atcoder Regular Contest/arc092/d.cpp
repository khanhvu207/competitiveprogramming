#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=2e5+5;
int n,a[N],b[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i) cin>>b[i];
	int res=0;
	for(int i=1;i<=29;++i){
		int mod=1<<i,k=1<<(i-1),cnt=0;
		vector<int> A,B;
		for(int j=0;j<n;++j) A.push_back(a[j]%mod);
		for(int j=0;j<n;++j) B.push_back(b[j]%mod);
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		for(int j=0;j<n;++j)
			if(A[j]<k){
				cnt+=upper_bound(B.begin(),B.end(),(1<<i)-1-A[j])-lower_bound(B.begin(),B.end(),k-A[j]);
			}
			else{
				cnt+=upper_bound(B.begin(),B.end(),(1<<i)-1-A[j])-B.begin();
				cnt+=upper_bound(B.begin(),B.end(),(1<<i)+k*2-1-A[j])-lower_bound(B.begin(),B.end(),(1<<i)+k-A[j]);
			}
		//cerr<<i<<' '<<cnt<<'\n';
		if(cnt&1) res|=1<<(i-1);
	}
	cout<<res<<'\n';
}


