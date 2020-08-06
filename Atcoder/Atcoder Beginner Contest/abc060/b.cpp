#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	for(int k=1;k<=b;++k)
		if(a*k%b==c){
			cout<<"YES\n";
			return 0;
		}
	cout<<"NO\n";
}


