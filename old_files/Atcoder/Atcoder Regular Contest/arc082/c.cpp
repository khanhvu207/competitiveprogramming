#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=1e5+5;
int n,cnt[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		cnt[x]++;
	}
	int res=0;
	for(int i=0;i<100000;++i){
		int sum=cnt[i]+cnt[i+1];
		if(i) sum+=cnt[i-1];
		res=max(res,sum);
	}
	cout<<res<<'\n';
}

