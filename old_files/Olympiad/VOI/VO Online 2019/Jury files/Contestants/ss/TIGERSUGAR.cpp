#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(ll i=0;i<(x);++i)
#define finc(i,a,b) for(int i=(a);i<=(b);++i)
#define fdec(i,a,b) for(int i=(a);i>=(b);--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define x first
#define y second
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
template <typename T> inline void read(T &x) {
    char c;
    bool neg=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-') neg=1, c=getchar();
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(neg) x=-x;
}
template <typename T> inline void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+48);
}
#define _ putchar(' ')
#define __ putchar('\n')
// -----------------------------------------------------------
const ll N=100000;
int n;
struct school{
    int x1,y1,x2,y2;
}a[N+2];
ll getlen(ll p){
    ll r=0;
    finc(i,1,n){
        if (a[i].x2<p) r+=p-a[i].x2;
        if (a[i].x1>p) r+=a[i].x1-p;
    }
    return r;
}
ll ans; ll best;
ll X[N+2];
void check(ll lp,ll p){
    if (ans>lp) ans=lp, best=p;
}
void get(){
    ans=getlen(a[1].x1); best=a[1].x1;
    int l=a[1].x1,r=a[2].x2;
    finc(i,1,n) l=min(l,a[i].x1),r=max(r,a[i].x2);
    for(;r-l>=3;){
        ll p1=l+(r-l)/3;
        ll p2=r-(r-l)/3;
        ll lp1=getlen(p1);
        ll lp2=getlen(p2);
        check(lp1,p1);
        check(lp2,p2);
        if (lp1<lp2) r=p2; else l=p1;
    }
    finc(p,l,r) check(getlen(p),p);
    finc(i,1,n){
        if (a[i].x2<best) X[i]=a[i].x2; else
        if (a[i].x1>best) X[i]=a[i].x1; else
        X[i]=best;
    }
}
ll res;
ii rr[N+2];
int main(){
    fast_io;
    freopen("tigersugar.inp","r",stdin);
    freopen("tigersugar.out","w",stdout);
    cin>>n;
    finc(i,1,n){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        if (a[i].x1>a[i].x2) swap(a[i].x1,a[i].x2);
        if (a[i].y1>a[i].y2) swap(a[i].y1,a[i].y2);
    }
    get();
    res+=ans;
    rr[0].x=best;
    finc(i,1,n) rr[i].x=X[i];

    finc(i,1,n) swap(a[i].x1,a[i].y1),swap(a[i].x2,a[i].y2);
    get();
    res+=ans;
    rr[0].y=best;
    finc(i,1,n) rr[i].y=X[i];

    cout << res << '\n';
    finc(i,0,n) cout << rr[i].x << ' ' << rr[i].y << '\n';
    return 0;
}


