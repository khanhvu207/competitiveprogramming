#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string n;
	cin>>n;
	string t=n;
	reverse(t.begin(),t.end());
	cout<<(n==t?"Yes\n":"No\n");
}

