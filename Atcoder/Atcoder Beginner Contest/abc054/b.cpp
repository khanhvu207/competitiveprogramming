#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
char a[55][55],b[55][55];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			cin>>b[i][j];
	for(int i=0;i<=n-m;++i)
		for(int j=0;j<=n-m;++j){
			bool ok=true;
			for(int x=0;x<m;++x)
				for(int y=0;y<m;++y)
					ok&=a[i+x][j+y]==b[x][y];
			if(ok)
				return puts("Yes\n"),0;
		}
	cout<<"No\n";
}


