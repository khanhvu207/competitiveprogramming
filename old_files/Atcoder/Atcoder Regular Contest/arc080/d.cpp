#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int h,w,n;
	cin>>h>>w>>n;
	int d=0,x=0,y=0;
	vector<vector<int>> res(h,vector<int>(w,0));
	for(int i=0;i<n;++i){
		int t;
		cin>>t;
		for(int j=0;j<t;++j){
			res[x][y]=i+1;
			if(x+dx[d]<0||x+dx[d]>=h||y+dy[d]<0||y+dy[d]>=w||res[x+dx[d]][y+dy[d]]!=0) d=(d+1)%4;
			x+=dx[d];
			y+=dy[d];
		}
	}
	for(int i=0;i<h;++i)
		for(int j=0;j<w;++j)
			cout<<res[i][j]<<" \n"[j==w-1];
}

