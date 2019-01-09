#include <bits/stdc++.h>

using namespace std;

int n;
long long x[100010],y[100010],a[100010],b[100010],resx,resy,w;

int main(){
    freopen("TIGERSUGAR.inp","r",stdin);
    freopen("TIGERSUGAR.out","w",stdout);

    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d %d %d %d",&x[i],&y[i],&a[i],&b[i]);

    sort(x+1,x+n+1);
    resx=x[(n+1)/2];
    sort(y+1,y+n+1);
    resy=y[(n+1)/2];

    for (int i=1; i<=n; i++)
        w+=abs(resx-a[i])+abs(resy-b[i]);
    cout<<w<<"\n";
    cout<<resx<<" "<<resy<<"\n";

    for (int i=1; i<=n; i++)
        cout<<a[i]<<" "<<b[i]<<"\n";

    return 0;
}
