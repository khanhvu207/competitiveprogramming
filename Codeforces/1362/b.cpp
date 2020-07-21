#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1111;
int a[N],cnt[N];

void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	if(n&1){
		cout<<-1<<'\n';
		return;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n-1;++i) for(int j=i+1;j<n;++j) ++cnt[a[i]^a[j]];
	for(int i=1;i<N;++i)
		if(cnt[i]*2==n){
			cout<<i<<'\n';
			return;
		}
	cout<<-1<<'\n';
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}