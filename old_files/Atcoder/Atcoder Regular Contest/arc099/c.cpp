#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	int i=0,res=0;
	while(i<n-1){
		i+=k-1;
		res++;
	}
	cout<<res<<'\n';
}

