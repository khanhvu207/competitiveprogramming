#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b,c;
	cin>>a>>b>>c;
	cout<<(a.back()==b[0]&&b.back()==c[0]?"YES\n":"NO\n");
}


