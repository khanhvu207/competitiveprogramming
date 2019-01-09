#include <bits/stdc++.h>

using namespace std;

const long double base=1e9;
int n,k;
struct point{
    int x,y,s;
};
point a[1000010],giasu;
long long res;

bool cmpx(point a, point b){
    return a.x<b.x;
}

bool cmpy(point a, point b){
    return a.y<b.y;
}

int main(){
    freopen("SIGNAL.inp","r",stdin);
    freopen("SIGNAL.out","w",stdout);

    scanf("%d %d",&n,&k);
    for (int i=1; i<=n; i++)
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].s);

    sort(a+1,a+n+1,cmpx);
    giasu.x=a[(n+1)/2].x;

    sort(a+1,a+n+1,cmpy);
    giasu.y=a[(n+1)/2].y;

    for (int i=1; i<=n; i++){
        long double x=abs(a[i].x-giasu.x);
        long double y=abs(a[i].y-giasu.y);
        long double s=a[i].s;
        s=((x+y)/s)*base;
        long long tmp=round(s);
        if ( tmp>res)
            res=tmp;
    }

    long double realres=res;
    realres/=base;
    if (k!=1) realres/=k;

    cout<<realres;

    return 0;
}
