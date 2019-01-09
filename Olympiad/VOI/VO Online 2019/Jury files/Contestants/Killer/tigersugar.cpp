#include <bits/stdc++.h>

using namespace std;

const long oo=1e9+7;
struct point
{
    long x;
    long y;
}a[100001][2];
long n,xmax=-oo,ymax=-oo,xmin=+oo,ymin=+oo;
bool kt=true;

void Docfile()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&a[i][1].x,&a[i][1].y,&a[i][2].x,&a[i][2].y);
        if ((a[i][1].x!=a[i][2].x) || (a[i][1].y!=a[i][2].y))
            kt=false;
        xmax=max(xmax,a[i][2].x);
        xmin=min(xmin,a[i][1].x);
        ymax=max(ymax,a[i][2].y);
        ymin=min(ymin,a[i][1].y);
    }
}

void Sub()
{
    long res=oo,tam,cur;
    point kq[n+1],tmp[n+1];
    long x1=max(a[1][1].x,a[2][1].x),x2=min(a[1][2].x,a[2][2].x),y1=max(a[1][1].y,a[2][1].y),y2=min(a[1][2].y,a[2][2].y);
    int flag=0;
    for (int i=3;i<=n;i++)
        if ((x1<=x2) && (y1<=y2))
        {
            x1=max(x1,a[i][1].x);
            x2=min(x2,a[i][2].x);
            y1=max(y1,a[i][1].y);
            y2=min(y2,a[i][2].y);
        }
        else
        {
            flag=1;
            break;
        }
    if ((!flag) && (x1<=x2) && (y1<=y2))
    {
        printf("%d\n",0);
        for (int i=1;i<=n+1;i++)
            printf("%d %d\n",x1,y1);
        return;
    }
    for (int j=ymin;j<=ymax;j++)
        for (int i=xmin;i<=xmax;i++)
        {
            tam=0;
            for (int t=1;t<=n;t++)
            {
                if ((a[t][1].x<=i) && (a[t][2].x>=i) && (a[t][1].y<=j) && (a[t][2].y>=j))
                {
                    tmp[t].x=i;
                    tmp[t].y=j;
                    continue;
                }
                cur=oo;
                for (int y=a[t][1].y;y<=a[t][2].y;y++)
                    for (int x=a[t][1].x;x<=a[t][2].x;x++)
                        if (abs(x-i)+abs(y-j)<cur)
                        {
                            cur=abs(x-i)+abs(y-j);
                            tmp[t].x=x;
                            tmp[t].y=y;
                        }
                tam+=cur;
            }
            if (tam<res)
            {
                res=tam;
                kq[0].x=i;
                kq[0].y=j;
                for (int t=1;t<=n;t++)
                {
                    kq[t].x=tmp[t].x;
                    kq[t].y=tmp[t].y;
                }
            }
        }
    printf("%d\n",res);
    for (int i=0;i<=n;i++)
        printf("%d %d\n",kq[i].x,kq[i].y);
}

void Sub2()
{
    long res=oo,tmp,x,y;
    for (int j=ymin;j<=ymax;j++)
        for (int i=xmin;i<=xmax;i++)
        {
            tmp=0;
            for (int t=1;t<=n;t++)
                if ((a[t][1].x!=i) || (a[t][1].y!=j))
                    tmp+=abs(a[t][1].x-i)+abs(a[t][1].y-j);
            if (tmp<res)
            {
                res=tmp;
                x=i;
                y=j;
            }
        }
    printf("%d\n",res);
    printf("%d %d\n",x,y);
    for (int i=1;i<=n;i++)
        printf("%d %d\n",a[i][1].x,a[i][1].y);
}

void Sub3()
{
    long res=oo,tam,cur;
    point kq[n+1],tmp[n+1];
    for (int vt=ymin;vt<=ymax;vt++)
    {
        tam=0;
        for (int i=1;i<=n;i++)
            if (abs(vt-a[i][1].y)<abs(vt-a[i][2].y))
            {
                tam+=abs(vt-a[i][1].y);
                tmp[i].x=0;
                tmp[i].y=a[i][1].y;
            }
            else
            {
                tam+=abs(vt-a[i][2].y);
                tmp[i].x=0;
                tmp[i].y=a[i][2].y;
            }
        if (tam<res)
        {
            res=tam;
            kq[0].x=0;
            kq[0].y=vt;
            for (int t=1;t<=n;t++)
            {
                kq[t].x=tmp[t].x;
                kq[t].y=tmp[t].y;
            }
        }
    }
    printf("%d\n",res);
    for (int i=0;i<=n;i++)
        printf("%d %d\n",kq[i].x,kq[i].y);
}

void Xuli()
{
    if (kt==true)
        Sub2();
    else
        if ((xmax==xmin) && (xmax==0))
            Sub3();
        else
            Sub();
}

int main()
{
    freopen("tigersugar.inp","r",stdin);
    freopen("tigersugar.out","w",stdout);
    Docfile();
    Xuli();
}
