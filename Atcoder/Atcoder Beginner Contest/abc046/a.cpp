#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	set<int> s;
	for(int i=0;i<3;++i){
		int x;
		cin>>x;
		s.insert(x);
	}
	cout<<int(s.size())<<'\n';
}


