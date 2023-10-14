#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int t,n;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,int>> a;
		vector<int> c;
		for(int i=0;i<n;++i){
			int x;cin>>x;
			a.emplace_back(x,i);
			c.push_back(x);
		}
		sort(a.begin(),a.end());
		int res=0;
		for(int i=0,j=0;i<n;++i){
			res=max(res,(int)((lower_bound(a.begin(),a.end(),pair<int,int>(a[i].first+1,n))-
						lower_bound(a.begin(),a.end(),pair<int,int>(a[i].first+1,a[i].second)))
						+(a.begin()+i+1-lower_bound(a.begin(),a.end(),pair<int,int>(a[i].first,0)))));
			if(i>0&&a[i-1].first==a[i].first) continue;
			while(j<n&&(i>=j||a[j].second>a[j-1].second)) ++j;
			int len=0;
			if(i>0) len+=lower_bound(a.begin(),a.end(),pair<int,int>(a[i-1].first,a[i].second))-lower_bound(a.begin(),a.end(),pair<int,int>(a[i-1].first,0));
			if(j<n) len+=lower_bound(a.begin(),a.end(),pair<int,int>(a[j].first,n))-lower_bound(a.begin(),a.end(),pair<int,int>(a[j].first,a[j-1].second));
			res=max(res,j-i+len);
		}
		cout<<n-res<<'\n';
	}
}