#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x,y;
	cin>>x>>y;
	int g[13];
	g[1]=0;
	g[2]=2;
	g[3]=0;
	g[4]=1;
	g[5]=0;
	g[6]=1;
	g[7]=0;
	g[8]=0;
	g[9]=1;
	g[10]=0;
	g[11]=1;
	g[12]=0;
	cout<<(g[x]==g[y]?"Yes\n":"No\n");
}


