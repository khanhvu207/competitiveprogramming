// relatively easy >.<

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=3e5+5;
const int K=5005;
int n,k;
ll a[N],f[K][K];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<=n%k;++i){
		for(int j=0;j<=(k-n%k);++j){
			f[i][j]=1e18;
			if(i==0&&j==0){
				f[i][j]=0;
				continue;
			}
			if(i>0){
				int cnt=(i-1)*(n/k+1)+j*(n/k);
				ll cost=a[cnt+n/k]-a[cnt];
				f[i][j]=min(f[i][j],f[i-1][j]+cost);
			}
			if(j>0){
				int cnt=i*(n/k+1)+(j-1)*(n/k);
				ll cost=a[cnt+n/k-1]-a[cnt];
				f[i][j]=min(f[i][j],f[i][j-1]+cost);
			}
		}
	}
	cout<<f[n%k][k-n%k];
}