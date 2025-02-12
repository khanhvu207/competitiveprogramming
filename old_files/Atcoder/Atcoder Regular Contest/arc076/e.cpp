#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;

const int N=1e5+5;
ll r,c,n;

bool isImportant(int x,int y){
	bool flagx=(x==0)||(x==r);
	bool flagy=(y==0)||(y==c);
	return flagx||flagy;
}

ll w(int x,int y){
	if(x==0) return y;
	if(y==c) return c+x;
	if(x==r) return 2*c+r-y;
	return 2*c+2*r-x;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>r>>c>>n;
	vector<P> p;
	for(int i=0;i<n;++i){
		int xa,ya,xb,yb;
		cin>>xa>>ya>>xb>>yb;
		if(isImportant(xa,ya)&&(isImportant(xb,yb))){
			ll x=w(xa,ya);
			ll y=w(xb,yb);
			p.emplace_back(x,i);
			p.emplace_back(y,i);
		}
	}
	sort(p.begin(),p.end());
	stack<ll> s;
	for(P i:p){
		if(s.empty()||s.top()!=i.second) s.push(i.second);
		else s.pop();
	}
	if(s.empty()) puts("YES");
	else puts("NO");
}


