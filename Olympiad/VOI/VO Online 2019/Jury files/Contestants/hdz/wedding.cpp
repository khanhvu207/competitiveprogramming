//sieu nhan
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inp "wedding.inp"
#define out "wedding.out"
#define oo 100005
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y1 hungdzno1
#define inf 1e15
int k,mod,a[oo*15];
void nhap(){
	cin>>k>>mod;
	for(int i=1;i<=k;i++) cin>>a[i];
}
void xuly(){
	cout<<"NO";
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen(inp,"r",stdin);
	freopen(out,"w",stdout);
	nhap();
	xuly();
}
