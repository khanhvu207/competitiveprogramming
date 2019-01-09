#include <bits/stdc++.h>
typedef struct o_struct {long long fx,fy,sx,sy,cs;}o;
using namespace std;
o a[200005];
long long d2,d1,n,x,y,res,l,r,mid,s1,s2,s3,re[200005];
bool ss(o x,o y)
{
    return x.fx < y.fx;
}
bool sss(o x,o y)
{
    return x.fy < y.fy;
}
bool ssss(o x,o y)
{
    return x.cs < y.cs;
}
long long tinh(long long x)
{
    long long je=0;
    for (int i=1;i<=n;i++)
        je+=abs(re[i]-x);
        return(je);
}
int main()
{
    freopen("tigersugar.inp","r",stdin);
    freopen("tigersugar.out","w",stdout);
    scanf("%lld",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld%lld",&a[i].fx,&a[i].fy,&a[i].sx,&a[i].sy);
        if (a[i].fy==a[i].sy) d1++;
        if (a[i].fx==a[i].sx) d2++;
        a[i].cs=i;
    }
    if (d1==d2 && d1==n)
    {
        sort(a+1,a+n+1,ss);
        x=a[(n+1)/2].fx;
        sort(a+1,a+n+1,sss);
        y=a[(n+1)/2].fy;
        for (int i=1;i<=n;i++)
            res+=abs(x-a[i].fx)+abs(y-a[i].fy);
        printf("%lld\n",res);
        printf("%lld %lld\n",x,y);
         sort(a+1,a+n+1,ssss);
        for (int i=1;i<=n;i++)
            printf("%lld %lld\n",a[i].fx,a[i].fy);

    }
    else
        if (d2==n)
    {
        l=0;r=1000000000;
        while (l<=r)
        {
            mid=(l+r)/2;
            x=mid;
            for (int i=1;i<=n;i++)
            if ((x>=a[i].fy && x<=a[i].sy) || (x<=a[i].fy && x>=a[i].sy))
                re[i]=x;
                else if (abs(x-a[i].sy)>abs(x-a[i].fy))
                    re[i]=a[i].fy;
                else re[i]=a[i].sy;
            s1=tinh(mid);
            x=mid-1;
            for (int i=1;i<=n;i++)
            if ((x>=a[i].fy && x<=a[i].sy) || (x<=a[i].fy && x>=a[i].sy))
                re[i]=x;
                else if (abs(x-a[i].sy)>abs(x-a[i].fy))
                    re[i]=a[i].fy;
                else re[i]=a[i].sy;
            s2=tinh(mid-1);
            x=mid+1;
            for (int i=1;i<=n;i++)
            if ((x>=a[i].fy && x<=a[i].sy) || (x<=a[i].fy && x>=a[i].sy))
                re[i]=x;
                else if (abs(x-a[i].sy)>abs(x-a[i].fy))
                    re[i]=a[i].fy;
                else re[i]=a[i].sy;
            s3=tinh(mid+1);
            if (s2 >= s1 && s3 >= s1)
            {
                x=mid;
            for (int i=1;i<=n;i++)
            if ((x>=a[i].fy && x<=a[i].sy) || (x<=a[i].fy && x>=a[i].sy))
                re[i]=x;
                else if (abs(x-a[i].sy)>abs(x-a[i].fy))
                    re[i]=a[i].fy;
                else re[i]=a[i].sy;
                 x=0;
                y=mid;
        printf("%lld\n",s1);
        printf("%lld %lld\n",x,y);
         sort(a+1,a+n+1,ssss);
        for (int i=1;i<=n;i++)
            printf("0 %lld\n",re[i]);
                return(0);
            }
            else if (s3<=s1 || s2>=s1) l=mid+1;
            else r=mid-1;
        }
    }
}
