#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int N=5005;
int n,m;
 
int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	int r=1;
	vector<int> res;
	while(m-(r-1)/2>=0&&(int)res.size()+1<=n) res.push_back(r),m-=(r-1)/2,++r;
	--r;
	for(int i=2;i<r&&m;++i) if(m-(r-i+1)/2>=0){
		res.push_back(r+i),m-=(r-i+1)/2;
		break;
	}
	if(m||(int)res.size()>n){cout<<-1; return 0;}
	for(int i=1;i<=1e9&&(int)res.size()<n;++i) res.push_back(1e8+1e4*(i+r+1)+1);
	for(int i:res) cout<<i<<' ';
}