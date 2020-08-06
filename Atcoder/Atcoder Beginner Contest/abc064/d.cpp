#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	stack<char> stk;
	for(char c:s){
		if(stk.empty()) stk.push(c);
		else{
			if(c==')'&&stk.top()=='(') stk.pop();
			else stk.push(c);
		}
	}
	while(!stk.empty()&&stk.top()=='(') s+=')',stk.pop();
	while(!stk.empty()) s='('+s,stk.pop();
	cout<<s<<'\n';
}


