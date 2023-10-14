#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int N=5e5+5;
int n,d,x[N],a[N],b[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>d;
	for(int i=0;i<n;++i) cin>>x[i];
	a[0]=d;
	for(int i=0;i<n;++i)
		a[i+1]=min(abs(a[i]-x[i]),a[i]);
	b[n]=1;
	for(int i=n-1;i;--i){
		b[i]=b[i+1];
		if(2*b[i+1]>x[i]) b[i]+=x[i];
	}
	int T;
	cin>>T;
	while(T--){
		int q;
		cin>>q;
		--q;
		cout<<(a[q]>=b[q+1]?"YES\n":"NO\n");
	}
}


