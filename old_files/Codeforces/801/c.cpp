#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const double eps=1e-6;
const int N=1e5+5;
int n,p,a[N],b[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>p;
	long long sum=0.0;
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(p>=sum){
		cout<<-1;
		return 0;
	}
	double l=0.0,r=1e16;
	for(int i=0;i<100;++i){
		double m=(l+r)/2.0;
		double total=0.0;
		for(int j=0;j<n;++j) total+=max(0.0,m*a[j]-b[j]*1.0);
		total/=m;
		if(total-p*1.0<eps) l=m;
		else r=m;
	}
	cout<<fixed<<setprecision(10)<<l;
}