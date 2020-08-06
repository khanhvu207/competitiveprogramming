#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int x,a,b;
	cin>>x>>a>>b;
	if(b<=a) cout<<"delicious\n";
	else if(b>a) cout<<(b-a<=x?"safe\n":"dangerous\n");
}


