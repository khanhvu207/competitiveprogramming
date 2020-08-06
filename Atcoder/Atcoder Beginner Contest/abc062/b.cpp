#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	char res[111][111];
	int w,h;
	cin>>w>>h;
	for(int i=0;i<111;++i)
		for(int j=0;j<111;++j)
			res[i][j]='#';
	for(int i=1;i<=w;++i)
		for(int j=1;j<=h;++j)
			cin>>res[i][j];
	for(int i=0;i<=w+1;++i){
		for(int j=0;j<=h+1;++j)
			cout<<res[i][j];
		cout<<'\n';
	}
}


