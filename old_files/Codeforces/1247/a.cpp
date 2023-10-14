#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a,b;
	cin>>a>>b;
	if(b-a>1){
		cout<<-1;
		return 0;
	}
	if(a>b&&((a==9&&b!=1)||a!=9)){
		cout<<-1;
		return 0;
	}
	int resa,resb;
	if(a==b){
		resa=a*100;
		resb=resa+1;
	}
	else{
		resa=a*100+99;
		resb=(a+1)*100;
	}
	cout<<resa<<' '<<resb;
}