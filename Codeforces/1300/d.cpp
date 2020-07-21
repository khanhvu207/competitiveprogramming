#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const double eps=1e-7;
const int N=1e5+5;
int n;
double x[N],y[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	if(n&1){cout<<"NO"; return 0;}
	for(int i=0;i<n;++i) cin>>x[i]>>y[i];
	double mx=(x[0]+x[n/2])/2.0,my=(y[0]+y[n/2])/2.0;
	for(int i=1;i<n/2;++i){
		double tx=(x[i]+x[(i+n/2)%n])/2.0;
		double ty=(y[i]+y[(i+n/2)%n])/2.0;
		if(fabs(tx-mx)>eps||fabs(ty-my)>eps){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}