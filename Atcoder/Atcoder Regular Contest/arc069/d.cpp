#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n;
string s;

void Try(int a,int b){
	vector<int> color(n);
	color[0]=a;
	color[1]=b;
	for(int i=2;i<n;++i){
		 if(color[i-1]) color[i]=color[i-2]^(s[i-1]=='x');
		 else color[i]=color[i-2]^(s[i-1]!='x');
	}
	if(color[n-1]&&((s[n-1]=='x')^(color[n-2]!=color[0]))) return;
	if(color[0]&&((s[0]=='x')^(color[n-1]!=color[1]))) return;
	if(!color[n-1]&&((s[n-1]=='x')^(color[n-2]==color[0]))) return;
	if(!color[0]&&((s[0]=='x')^(color[n-1]==color[1]))) return;
	for(int i=0;i<n;++i)
		cout<<(color[i]?'S':'W');
	cout<<'\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			Try(i,j);
	cout<<-1<<'\n';
}

