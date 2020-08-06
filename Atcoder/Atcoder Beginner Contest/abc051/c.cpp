#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int sx,sy,tx,ty;
	cin>>sx>>sy>>tx>>ty;
	int dx=tx-sx;
	int dy=ty-sy;
	for(int i=0;i<dx;++i) cout<<'R';
	for(int i=0;i<dy;++i) cout<<'U';
	for(int i=0;i<dx;++i) cout<<'L';
	for(int i=0;i<dy;++i) cout<<'D';
	cout<<'D';
	for(int i=0;i<dx+1;++i) cout<<'R';
	for(int i=0;i<dy+1;++i) cout<<'U';
	cout<<'L';
	cout<<'U';
	for(int i=0;i<dx+1;++i) cout<<'L';
	for(int i=0;i<dy+1;++i) cout<<'D';
	cout<<'R';
	cout<<endl;
}


