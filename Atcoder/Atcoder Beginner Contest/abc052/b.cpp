#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int x=0,res=0;
	for(int i=0;i<n;++i){
		x+=s[i]=='I'?1:-1;
		res=max(res,x);
	}
	cout<<res<<'\n';
}


