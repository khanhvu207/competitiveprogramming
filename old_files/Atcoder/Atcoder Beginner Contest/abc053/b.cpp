#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	int i=0,j=n-1;
	while(i<n&&s[i]!='A') ++i;
	while(~j&&s[j]!='Z') --j;
	cout<<(i>j?0:j-i+1)<<'\n';
}


