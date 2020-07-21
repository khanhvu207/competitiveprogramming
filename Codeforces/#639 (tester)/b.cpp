#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=50005;
ll a[MX];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for(int i=1;i<MX;++i) a[i]=i*(i+1)*1LL+(i-1)*i*1LL/2LL;
	int t;
	cin>>t;
	while(t--){
		ll n; cin>>n;
		int res=0;
		while(n>=2){
			int p=lower_bound(a+1,a+MX,n)-a;
			while(a[p]>n) --p;
			n-=a[p];
			++res;
		}
		cout<<res<<'\n';
	}
}