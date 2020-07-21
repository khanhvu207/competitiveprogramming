#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX=2e5+5;
int n,res[MX];
array<int,3> seg[MX];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;++i){ 
		cin>>seg[i][0]>>seg[i][1];
		seg[i][2]=i;
	}
}