#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a[3];
	const char w[3]={'A','B','C'};
	cin>>a[0]>>a[1]>>a[2];
	for(int i=0;i<3;++i){
		reverse(a[i].begin(),a[i].end());
		transform(a[i].begin(),a[i].end(),a[i].begin(),::toupper);
	}
	int c=0;
	while(true){
		if(a[c].empty()){
			cout<<w[c]<<'\n';
			return 0;
		}
		int x=a[c].back()-'A';
		a[c].pop_back();
		c=x;
	}
}


