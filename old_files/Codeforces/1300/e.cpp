#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const double eps=1e-11;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	stack<pair<double,int>> S;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		double t=x;
		if(S.empty()) S.push(make_pair(t,1));
		else{
			int len=1;
			while(!S.empty()&&((t*len+S.top().fi*S.top().se)-S.top().fi*(S.top().se+len)<-eps)){
				t=(t*len+S.top().fi*S.top().se)/(S.top().se+len);
				len+=S.top().se;
				S.pop();
			}
			S.push(make_pair(t,len));
		}
	}
	vector<double> res;
	while(!S.empty()){
		for(int i=0;i<S.top().se;++i) res.push_back(S.top().fi);
		S.pop();
	}
	reverse(res.begin(),res.end());
	for(double x:res) cout<<fixed<<setprecision(11)<<x<<'\n';
}