#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int k;
	cin>>k;
	int n=s.size();
	set<string> Set;
	for(int len=1;len<=k;++len){
		for(int i=0;i+len-1<n;++i){
			Set.insert(s.substr(i,len));
		}
	}
	auto it=Set.begin();
	while(--k) it++;
	cout<<*it<<'\n';
}
