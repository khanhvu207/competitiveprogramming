/*
	Google search picture: hexagon in a square
	and you get the idea... 
	Rotate pi/4
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const double eps=1e-7;
const double pi=atan(1)*4;
int t;
double n;

double solve(){
	cin>>n;
	double res=cos(pi/n/4.0)/sin(pi/n/2.0);
	return res;
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--){
		cout<<fixed<<setprecision(7)<<solve()<<'\n';
	}
}