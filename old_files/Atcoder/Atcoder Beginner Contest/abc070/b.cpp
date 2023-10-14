#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max(0,min(b,d)-max(a,c))<<'\n';
}


