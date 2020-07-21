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
	int k;
	cin>>k;
	int f=(1<<18)-1;
	int g=1<<17;
	cout<<3<<' '<<3<<'\n';
	cout<<f<<' '<<f<<' '<<k<<'\n';
	cout<<f<<' '<<g<<' '<<f<<'\n';
	cout<<k<<' '<<f<<' '<<k<<'\n';
}