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
	int res=0,two=0;
	for(int i=1;i<N;++i){
		if(!cnt[i]) continue;
		if(cnt[i]>=3)
			cnt[i]=(cnt[i]&1)?1:2;
		if(cnt[i]==2) two++;
		else res++;
	}
	res+=two;
	if(two&1) res--;
	cout<<res<<'\n';
}
