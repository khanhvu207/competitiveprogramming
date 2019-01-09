#include <bits/stdc++.h>
#define N 100005

using namespace std;
typedef long long ll;
int n;
ll x1[N], x2[N], y1[N], y2[N];
bool sub2;

void solve2()
{
    ll ans=0;
    for(int i=2; i<=n; ++i)
        ans+=abs(x1[i]-x1[1])+abs(y1[i]-y1[1]);
    cout<<ans;
}

int main()
{
    freopen("TIGERSUGAR.INP","r",stdin);
    freopen("TIGERSUGAR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sub2=true;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        if(x1[i]!=x2[i] && y1[i]!=y2[i]) sub2=false;
    }
    if(sub2) solve2();
    //else
    return 0;
}
