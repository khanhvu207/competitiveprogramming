#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<"99 99\n";
	vector<vector<char>> res(99,vector<char>(99,'.'));
	int x=1,y=1;
	for(int i=0;i<a-1;++i){
		res[x-1][y-1]='#';
		res[x-1][y]='#';
		res[x-1][y+1]='#';
		res[x][y-1]='#';
		res[x][y+1]='#';
		res[x+1][y-1]='#';
		res[x+1][y]='#';
		res[x+1][y+1]='#';
		if(y+3>=99) y=1,x+=3;
		else y+=3;
	}
	for(int i=0;i<b-1;++i){
		res[x][y]='#';
		if(y+3>=99) y=1,x+=3;
		else y+=3;
	}
	if(a==1){
		res[x][y]='#';
	}
	for(int i=0;i<99;++i){
		for(int j=0;j<99;++j)
			cout<<res[i][j];
		cout<<'\n';
	}
}


