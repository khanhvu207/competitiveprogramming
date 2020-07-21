#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n,l[30],m[30],w[30],pow3[20],res=-1e9,s1=-1,s2=-1;
map<pair<int,int>,int> Map,State;

void Go1(int cur,int a,int b,int c,int mask){
	if(cur==n/2){
		pair<int,int> x={a-b,b-c};
		if(!Map.count(x)||Map[x]<a) Map[x]=a,State[x]=mask;
		return;
	}
	Go1(cur+1,a+l[cur],b+m[cur],c,mask);
	Go1(cur+1,a,b+m[cur],c+w[cur],mask+1*pow3[cur]);
	Go1(cur+1,a+l[cur],b,c+w[cur],mask+2*pow3[cur]);
}

void Go2(int cur,int a,int b,int c,int mask){
	if(cur==n){
		pair<int,int> x={b-a,c-b};
		if(Map.count(x)&&Map[x]+a>res){
			res=Map[x]+a;
			s1=State[x];
			s2=mask;
		}
		return;
	}
	Go2(cur+1,a+l[cur],b+m[cur],c,mask);
	Go2(cur+1,a,b+m[cur],c+w[cur],mask+1*pow3[cur-n/2]);
	Go2(cur+1,a+l[cur],b,c+w[cur],mask+2*pow3[cur-n/2]);
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pow3[0]=1;
	for(int i=1;i<15;++i) pow3[i]=pow3[i-1]*3;
	cin>>n;
	for(int i=0;i<n;++i) cin>>l[i]>>m[i]>>w[i];
	if(n==1){
		if(!l[0]&&l[0]==m[0]) cout<<"LM\n";
		else if(!m[0]&&m[0]==w[0]) cout<<"MW\n";
		else if(!l[0]&&l[0]==w[0]) cout<<"LW\n";
		else cout<<"Impossible\n";
		return 0;
	}
	Go1(0,0,0,0,0);
	Go2(n/2,0,0,0,0);
	if(s1==-1) cout<<"Impossible\n";
	else{
		for(int i=0;i<n/2;++i){
			if(s1%3==0) cout<<"LM\n";
			else if(s1%3==1) cout<<"MW\n";
			else cout<<"LW\n";
			s1/=3;
		}
		for(int i=0;i<n-n/2;++i){
			if(s2%3==0) cout<<"LM\n";
			else if(s2%3==1) cout<<"MW\n";
			else cout<<"LW\n";
			s2/=3;
		}
	}
}