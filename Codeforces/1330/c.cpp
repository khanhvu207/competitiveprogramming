#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=1e5+5;
int n,m,a[MX];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<m;++i) cin>>a[i];
	ll sum=accumulate(a,a+m,0LL);
	if(n>sum){
		cout<<-1;
		return 0;
	}
	int pos=1,N=n;
	vector<int> res;
	for(int i=0;i<m;++i){
		if(pos+a[i]-1>N){
			cout<<-1;
			return 0;
		}
		res.push_back(pos);
		int len=max(1LL,n-sum+a[i]);
		pos+=len;
		n-=len;
		sum-=a[i];
	}
	for(int x:res) cout<<x<<' ';
}
