#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b;
	cin>>a>>b;
	if(a.size()<b.size()) cout<<"LESS\n";
	else if(a.size()>b.size()) cout<<"GREATER\n";
	else{
		if(a==b){
			cout<<"EQUAL\n";
			return 0;
		}
		for(int i=0;i<int(a.size());++i)
			if(a[i]<b[i]){
				cout<<"LESS\n";
				return 0;
			} 
			else if(a[i]>b[i]){
				cout<<"GREATER\n";
				return 0;
			}
	}
}


