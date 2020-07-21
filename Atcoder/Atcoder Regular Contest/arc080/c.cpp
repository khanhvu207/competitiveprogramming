#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;
	cin>>n;
	ll odd=0,two=0,four=0;
	for(int i=0;i<n;++i){
		ll x;
		cin>>x;
		odd+=x&1;
		if(x%2==0&&x%4!=0) two++;
		if(x%4==0) four++;
	}
	n-=two;
	if(!n||(!two&&four+1>=odd)||(two&&four==odd)) cout<<"Yes\n";
	else cout<<"No\n";
}

