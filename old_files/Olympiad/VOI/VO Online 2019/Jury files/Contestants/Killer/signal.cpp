#include <bits/stdc++.h>

using namespace std;

struct Data
{
    int x;
    int y;
    int s;
}a[50001];
#define esp 1e-6
int k,n,xmin=1e9+7,xmax=-1e9+7,ymin=1e9+7,ymax=-1e9+7;

void Docfile()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].s);
        xmin=min(xmin,a[i].x);
        xmax=max(xmax,a[i].x);
        ymin=min(ymin,a[i].y);
        ymax=max(ymax,a[i].y);
    }
}

int Check(double s)
{
    for (int j=ymin;j<=ymax;j++)
        for (int i=xmin;i<=xmax;i++)
        {
            int flag=0;
            for (int t=1;t<=n;t++)
                if (abs(a[t].x-i)+abs(a[t].y-j)>s*a[t].s)
                {
                    flag=1;
                    break;
                }
            if (flag==0)
                return 1;
        }
    return 0;
}

void Xuli()
{
    double d=0,c=1e7,g,res=1e9;
    while (c-d>esp)
    {
        g=(d+c)/2;
        if (Check(g))
        {
            res=min(res,g);
            c=g;
        }
        else
            d=g;
    }
    printf("%.6f",res);
}

int main()
{
    freopen("signal.inp","r",stdin);
    freopen("signal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Docfile();
    Xuli();
}
