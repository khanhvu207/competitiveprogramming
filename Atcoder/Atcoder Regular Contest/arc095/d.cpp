#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	sort(a.begin(),a.end());
	int mid1=a[n-1]/2,mid2=(a[n-1]+1)/2,best=2*a[n-1],res;
	for(int i=0;i<n-1;++i)
		if(a[i]<=mid1){
			if(mid1-a[i]<best){
				best=mid1-a[i];
				res=a[i];
			}
		}
		else if(a[i]>=mid2){
			if(a[i]-mid2<best){
				best=a[i]-mid2;
				res=a[i];
			}
		}
	cout<<a[n-1]<<' '<<res<<'\n';
}


