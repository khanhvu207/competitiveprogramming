#include <iostream>
#include <cstdio>
#define N 100001
#define lli long long
#define vc 1000000000
#define infi 1000000000000000000LL
using namespace std;
int n;
struct kdl{int x1,x2,y1,y2;} a[N];
void nhap(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        if (a[i].x1>a[i].x2) swap(a[i].x1,a[i].x2);
        if (a[i].y1>a[i].y2) swap(a[i].y1,a[i].y2);
    }
}
lli ktX(int u){
    lli t=0;
    for (int i=1;i<=n;++i){
        if (u<a[i].x1||u>a[i].x2) t+=min(abs(u-a[i].x1),abs(u-a[i].x2));
    }
    return t;
}
lli ktY(int u){
    lli t=0;
    for (int i=1;i<=n;++i){
        if (u<a[i].y1||u>a[i].y2) t+=min(abs(u-a[i].y1),abs(u-a[i].y2));
    }
    return t;
}
bool MIN(lli &u,const lli &v){if (v<u) {u=v;return true;} return false;}
lli mana;
int TX(){
    int l=0,r=vc,mid,ans;
    lli kq=infi,u,v;
    while(l<=r){
        mid=(l+r)>>1;
        u=ktX(mid),v=ktX(mid+1);
        if (MIN(kq,u)) kq=u,ans=mid;
        if (u>v) l=mid+1; else r=mid-1;
    }
    mana+=kq;
    return ans;
}
int TY(){
    int l=0,r=vc,mid,ans;
    lli kq=infi,u,v;
    while(l<=r){
        mid=(l+r)>>1;
        u=ktY(mid),v=ktY(mid+1);
        if (MIN(kq,u)) kq=u,ans=mid;
        if (u>v) l=mid+1; else r=mid-1;
    }
    mana+=kq;
    return ans;
}
int main(){
    freopen("TIGERSUGAR.inp","r",stdin);
    freopen("TIGERSUGAR.out","w",stdout);
    nhap();
    int xx,yy;
    xx=TX(),yy=TY();
    printf("%lld\n%d %d\n",mana,xx,yy);
    for (int i=1;i<=n;++i){
        if (a[i].x1<=xx&&xx<=a[i].x2) printf("%d ",xx);
        else if (abs(a[i].x1-xx)<abs(a[i].x2-xx)) printf("%d ",a[i].x1);
        else printf("%d ",a[i].x2);
        if (a[i].y1<=yy&&yy<=a[i].y2) printf("%d\n",yy);
        else if (abs(a[i].y1-yy)<abs(a[i].y2-yy)) printf("%d\n",a[i].y1);
        else printf("%d\n",a[i].y2);
    }
}
