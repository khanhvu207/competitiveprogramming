#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	vector<string> s;
	int n,l;
	cin>>n>>l;
	for(int i=0;i<n;++i){
		string x;
		cin>>x;
		s.push_back(x);
	}
	sort(s.begin(),s.end());
	for(string& x:s)
		cout<<x;
	cout<<'\n';
}


