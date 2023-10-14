#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int k,s,res=0;
	cin>>k>>s;
	for(int i=0;i<=k;++i)
		for(int j=0;j<=k;++j)
			if(s-i-j>=0&&s-i-j<=k) res++;
	cout<<res<<'\n';
}


