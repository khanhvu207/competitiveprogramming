#include<bits/stdc++.h>

using namespace std;

#define fi "tigersugar.inp"
#define fo "tigersugar.out"
#define maxn 100005
#define For(i,a,b) for(int i=a;i<=b;i++)
#define tr(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int n;
int x1[maxn],yy1[maxn],x2[maxn],y2[maxn];


int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    scanf("%d",&n);
    int d=0;
    For(i,1,n) {
        scanf("%d %d %d %d",&x1[i],&yy1[i],&x2[i],&y2[i]);
        if (x1[i]==x2[i] && yy1[i]==y2[i]) d++;
    }
    if (d==n) {
        sort(x1+1,x1+n+1);
        sort(yy1+1,yy1+n+1);
        int64_t res=0;
            int xx=x1[n/2+1],yy=yy1[n/2+1];
            For(i,1,n) res+=(int64_t) abs(xx-x1[i])+(int64_t) abs(yy-yy1[i]);
            cout<<res<<"\n";
            cout<<xx<<" "<<yy<<"\n";
            For(i,1,n) printf("%d %d\n",x2[i],y2[i]);
    }

    return 0;
}
