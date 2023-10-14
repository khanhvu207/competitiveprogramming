#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	vector<int> pf(n+1,0);
	for(int i=0;i<n;++i)
		pf[i+1]=pf[i]+(s[i]=='0');
	int k=n;
	while(pf[n-k]-pf[k]!=0&&pf[n-k]-pf[k]!=n-2*k) k--;
	cout<<k<<'\n';
}


