#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	vector<int> res;
	for(char c:s)
		switch(c){
			case '0':
				res.push_back(0);
				continue;
			case '1':
				res.push_back(1);
				continue;
			case 'B':
				if(!res.empty()) res.pop_back();
				continue;
		}
	for(int x:res)
		cout<<x;
	cout<<'\n';
}


