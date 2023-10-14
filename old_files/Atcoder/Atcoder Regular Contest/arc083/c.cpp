#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	double density=0;
	int t=0,s=0;
	for(int i=0;i<=50;++i)
		for(int j=0;j<=50;++j)
			for(int k=0;k<=50;++k)
				for(int g=0;g<=50;++g){
					int water=i*a+j*b;
					int sugar=k*c+g*d;
					int req=sugar/e+(sugar%e!=0);
					if(water>=req&&100*water+sugar<=f){
						double cur_dense=100.0*sugar/(water*1.0+sugar*1.0);
						if(cur_dense>=density){
							density=cur_dense;
							t=100*water+sugar;
							s=sugar;
						}
					}
				}
	cout<<t<<' '<<s<<'\n';
}

