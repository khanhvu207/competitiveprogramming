#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int w,h,n;
	cin>>w>>h>>n;
	int res[w+5][h+5];
	memset(res,0,sizeof res);
	for(int i=0;i<n;++i){
		int x,y,a;
		cin>>x>>y>>a;
		if(a==1){
			for(int i=1;i<=x;++i)
				for(int j=1;j<=h;++j)
					res[i][j]=1;
		}
		if(a==2){
			for(int i=x+1;i<=w;++i)
				for(int j=1;j<=h;++j)
					res[i][j]=1;
		}
		if(a==3){
			for(int i=1;i<=w;++i)
				for(int j=1;j<=y;++j)
					res[i][j]=1;
		}
		if(a==4){
			for(int i=1;i<=w;++i)
				for(int j=y+1;j<=h;++j)
					res[i][j]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=w;++i)
		for(int j=1;j<=h;++j)
			cnt+=res[i][j]==0;
	cout<<cnt<<'\n';

}


