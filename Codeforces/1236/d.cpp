// simulate the process...
// what a toxic problem :/
// UPD1: overflow again, nani ?!?
// UPD2: tricky case where you turn right at (1, 1)

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int N=1e5;
int n,m,k,ct,l,r,u,d;
set<int> row[N+5],col[N+5];

ll Go(int x,int y,int dir){
	// cerr<<x<<' '<<y<<' '<<dir<<'\n';
	// ++ct;
	// if(ct>10) return 0;
	ll cnt=0;
	if(dir==0){
		auto it=row[x].upper_bound(y);
		int ny=*it-1;
		ny=min(ny,r);
		u=x+1;
		if(ny==y) return 1;
		cnt=ny-y+Go(x,ny,(dir+1)%4);
	}
	else if(dir==1){
		auto it=col[y].upper_bound(x);
		int nx=*it-1;
		nx=min(nx,d);
		r=y-1;
		if(nx==x) return 1;
		cnt=nx-x+Go(nx,y,(dir+1)%4);
	}
	else if(dir==2){
		auto it=row[x].lower_bound(y);
		while(*it>=y) --it;
		int ny=*it+1;
		ny=max(ny,l);
		d=x-1;
		if(ny==y) return 1;
		cnt=y-ny+Go(x,ny,(dir+1)%4);
	}
	else{
		auto it=col[y].lower_bound(x);
		while(*it>=x) --it;
		int nx=*it+1;
		nx=max(nx,u);
		l=y+1;
		if(nx==x) return 1;
		cnt=x-nx+Go(nx,y,(dir+1)%4);
	}
	return cnt;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		row[i].insert(0);
		row[i].insert(m+1);
	}
	for(int i=1;i<=m;++i){
		col[i].insert(0);
		col[i].insert(n+1);
	}
	for(int i=0;i<k;++i){
		int x,y;
		cin>>x>>y;
		row[x].insert(y);
		col[y].insert(x);
	}
	l=1,r=m,u=1,d=n;
	ll total=Go(1,1,0);
	l=1,r=m,u=1,d=n;
	total=max(total,Go(1,1,1));
	ll goal=1LL*n*m-k;
	cout<<(total==goal?"Yes\n":"No\n");
}