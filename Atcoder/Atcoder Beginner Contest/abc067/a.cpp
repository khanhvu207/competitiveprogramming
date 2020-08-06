#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b;
	cin>>a>>b;
	cout<<(a%3==0||b%3==0||(a+b)%3==0?"Possible\n":"Impossible\n");
}


