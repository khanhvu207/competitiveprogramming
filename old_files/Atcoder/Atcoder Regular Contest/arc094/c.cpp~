#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	int pa=a&1,pb=b&1,pc=c&1;
	if(pa==pb&&pb==pc){
		int t=max({a,b,c});
		cout<<(3*t-a-b-c)/2<<'\n';
		return 0;
	}
	if(pa==pb) a++,b++;
	else if(pb==pc) b++,c++; 
	else if(pc==pa) c++,a++;
	int t=max({a,b,c});
	cout<<(3*t-a-b-c)/2+1<<'\n';
}

