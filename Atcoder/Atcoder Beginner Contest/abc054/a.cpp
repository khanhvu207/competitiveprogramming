#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b;
	cin>>a>>b;
	if(a==1) a=14;
	if(b==1) b=14;
	if(a==b) cout<<"Draw\n";
	else cout<<(a<b?"Bob\n":"Alice\n");
}


