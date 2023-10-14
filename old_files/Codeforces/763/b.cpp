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
	int n;
	cin>>n;
	cout<<"YES\n";
	while(n--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<2*(x1&1)+(y1&1)+1<<'\n';
	}
}