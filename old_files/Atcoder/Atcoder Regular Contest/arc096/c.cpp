#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c,x,y,cost=0;
	cin>>a>>b>>c>>x>>y;
	if(a+b>2*c){
		int t=min(x,y);
		cost+=t*2*c;
		x-=t;
		y-=t;
		if(x){
			if(a<2*c) cost+=a*x;
			else cost+=2*c*x;
		}
		else{
			if(b<2*c) cost+=b*y;
			else cost+=2*c*y;
		}
	}
	else{
		cost=x*a+b*y;
	}
	cout<<cost<<'\n';
}

