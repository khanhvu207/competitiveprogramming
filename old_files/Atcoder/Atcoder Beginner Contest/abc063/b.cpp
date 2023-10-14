#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	set<int> Set;
	cin>>s;
	for(char c:s) 
		Set.insert(c);
	cout<<(int(Set.size())==int(s.size())?"yes\n":"no\n");
}


