#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=55;
int n,a,b;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a>>b;
	vector<ll> arr(n);
	for(ll& x:arr) cin>>x;
	sort(arr.begin(),arr.end(),greater<ll>());
	double res=1.0*accumulate(arr.begin(),arr.begin()+a,0LL)/a;
	cout<<fixed<<setprecision(7)<<res<<'\n';
	ll C[55][55];
	for(int i=0;i<=50;++i)
		C[i][0]=1;
	C[1][1]=1;
	for(int i=2;i<=50;++i)
		for(int j=1;j<=50;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	int num=0,need=0;
	for(int i=0;i<n;++i){
		if(arr[i]==arr[a-1]){
			++num;
			if(i<a) ++need;
		}
	}
	ll ways=C[num][need];
	for(int i=a;i<b;++i){
		if(arr[i]==arr[0]) 
			ways+=C[num][i+1];
	}
	cout<<ways<<'\n';
}


