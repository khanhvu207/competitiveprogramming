#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int r,g,b;
		cin>>r>>g>>b;
		vector<ll> x(r),y(g),z(b);
		for(ll& a:x) cin>>a;
		for(ll& a:y) cin>>a;
		for(ll& a:z) cin>>a;
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		sort(z.begin(),z.end());
		ll res=numeric_limits<ll>::max();
		for(ll X:x){
			int posY=lower_bound(y.begin(),y.end(),X)-y.begin();
			int posZ=lower_bound(z.begin(),z.end(),X)-z.begin();
			for(int j=max(posY-3,0);j<=min(posY+3,(int)y.size()-1);++j)
				for(int k=max(posZ-3,0);k<=min(posZ+3,(int)z.size()-1);++k)
					res=min(res,(X-y[j])*(X-y[j])+(X-z[k])*(X-z[k])+(y[j]-z[k])*(y[j]-z[k]));
		}
		for(ll Y:y){
			int posX=lower_bound(x.begin(),x.end(),Y)-x.begin();
			int posZ=lower_bound(z.begin(),z.end(),Y)-z.begin();
			for(int j=max(posX-3,0);j<=min(posX+3,(int)x.size()-1);++j)
				for(int k=max(posZ-3,0);k<=min(posZ+3,(int)z.size()-1);++k)
					res=min(res,(Y-x[j])*(Y-x[j])+(Y-z[k])*(Y-z[k])+(x[j]-z[k])*(x[j]-z[k]));
		}
		for(ll Z:z){
			int posY=lower_bound(y.begin(),y.end(),Z)-y.begin();
			int posX=lower_bound(x.begin(),x.end(),Z)-x.begin();
			for(int j=max(posY-3,0);j<=min(posY+3,(int)y.size()-1);++j)
				for(int k=max(posX-3,0);k<=min(posX+3,(int)x.size()-1);++k)
					res=min(res,(Z-y[j])*(Z-y[j])+(Z-x[k])*(Z-x[k])+(y[j]-x[k])*(y[j]-x[k]));
		}
		cout<<res<<'\n';
	}
}