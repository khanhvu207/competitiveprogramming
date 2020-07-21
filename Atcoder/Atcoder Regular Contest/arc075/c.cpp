#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,sum=0;
	cin>>n;
	vector<int> a(n);
	for(int& x:a){
		cin>>x;
		sum+=x;
	}
	if(sum%10==0){
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i)
			if(a[i]%10){
				sum-=a[i];
				break;
			}
	}
	cout<<(sum%10==0?0:sum)<<'\n';
}

