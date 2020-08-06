#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b;
	cin>>a>>b;
	int token=0,i=0,j=0;
	int len=a.size()+b.size();
	while(i+j<len){
		if(token) cout<<b[j++];
		else cout<<a[i++];
		token^=1;
	}
	cout<<endl;
}


