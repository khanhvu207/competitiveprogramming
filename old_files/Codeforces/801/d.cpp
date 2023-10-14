#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=1e3+5;
double x[N],y[N],res=1e18;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>x[i]>>y[i];
	for(int i=0,j=1,k=2;i<n;){
		double ax=x[j]-x[i],ay=y[j]-y[i];
		double bx=x[k]-x[i],by=y[k]-y[i];
		double h=fabs(ax*by-bx*ay)/hypot(by,bx);
		res=min(res,h/2.0);
		++i;
		j=(j+1)%n;
		k=(k+1)%n;
	}
	cout<<fixed<<setprecision(10)<<res;
}