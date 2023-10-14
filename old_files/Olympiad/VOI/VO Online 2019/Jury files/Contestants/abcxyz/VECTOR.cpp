#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
long long a,b,ga,gb,t,x;
int n,m,cnt;
int main()
{
    freopen("VECTOR.inp","r",stdin);
    freopen("VECTOR.out","w",stdout);
    cin>>n;
    a=1;b=1;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a=(a*x)%MOD;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        b=(b*x)%MOD;
    }
    t=__gcd(a,b);
    ga=t/a;
    gb=t/b;
    cnt=6;
    if(ga==1) cnt-=2;
    if(gb==1) cnt--;
    if(t==1) cnt-=3;
    cout<<cnt<<endl;
    if(ga!=1) cout<<ga*ga<<" D"<<endl;
    if(gb!=1) cout<<gb<<" D"<<endl;
    if(t!=1) cout<<t<<" D"<<endl;
    if(ga!=1) cout<<ga<<" W"<<endl;
    if(t!=1) cout<<t<<" W"<<endl;
    if(t!=1) cout<<t<<" L"<<endl;
}
