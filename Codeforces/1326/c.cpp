#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=998244353;
int n,k;
pair<int,int> A[200005];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>A[i].fi;
		A[i].se=i;
	}
	sort(A,A+n);
	vector<int> idx;
	ll res=0LL,ways=1LL;
	for(int i=n-1;i>=n-k;--i){
		res+=A[i].fi;
		idx.push_back(A[i].se);
	}
	sort(idx.begin(),idx.end());
	for(int i=1;i<(int)idx.size();++i) (ways*=(idx[i]-idx[i-1]+MOD)%MOD)%=MOD;
	cout<<res<<' '<<ways;
}