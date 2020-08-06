#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int w,a,b;
	cin>>w>>a>>b;
	if(b>a+w) cout<<b-a-w<<'\n';
	else if(a>b+w) cout<<a-b-w<<'\n';
	else cout<<0<<'\n';
}


