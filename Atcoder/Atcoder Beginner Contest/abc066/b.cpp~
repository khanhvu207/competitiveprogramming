#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	while(!s.empty()){
		int len=s.size();
		if(len&1){
			s.pop_back();
			continue;
		}
		string a=s.substr(0,len/2);
		string b=s.substr(len/2,len/2);
		if(a==b&&len!=n){
			cout<<len<<'\n';
			return 0;
		}
		s.pop_back();
	}
}


