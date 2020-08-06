#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
int n;
ll k,bit[N],pf[N];

void upd(int x){
	for(;x<N;x=x|(x+1))
		bit[x]++;
}

ll get(int x){
	ll res=0;
	for(;x>=0;x=(x&(x+1))-1)
		res+=bit[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	vector<ll> b;
	for(int i=1;i<=n;++i){
		cin>>pf[i];
		pf[i]+=pf[i-1];
		b.push_back(pf[i]-1LL*k*i);
	}
	b.push_back(0);
	sort(b.begin(),b.end());
	ll res=0;
	upd(lower_bound(b.begin(),b.end(),0)-b.begin());
	for(int i=1;i<=n;++i){
		int x=lower_bound(b.begin(),b.end(),pf[i]-1LL*k*i)-b.begin();
		res+=get(x);
		upd(x);
	}
	cout<<res<<'\n';
}


