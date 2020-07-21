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
	int n,m,p,vt1=-1,vt2=-1;
	cin>>n>>m>>p;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(vt1==-1&&__gcd(p,x)==1) vt1=i;
	}
	for(int i=0;i<m;++i){
		int x;
		cin>>x;
		if(vt2==-1&&__gcd(p,x)==1) vt2=i;
	}
	cout<<vt1+vt2;
}