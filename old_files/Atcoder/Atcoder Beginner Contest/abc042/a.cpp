#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	array<int,3> a,b;
	a={5,5,7};
	cin>>b[0]>>b[1]>>b[2];
	sort(b.begin(),b.end());
	cout<<(a==b?"YES\n":"NO\n");
}

