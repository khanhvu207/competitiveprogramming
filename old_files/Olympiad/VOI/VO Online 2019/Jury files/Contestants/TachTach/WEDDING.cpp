#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define N 1500001
#define lli long long
using namespace std;
int p[N],MOD,k;
int pw(int u,int c){
    if (!c) return 1;
    lli tmp=pw(u,c>>1);
    tmp*=tmp;
    if (tmp>=MOD) tmp%=MOD;
    if (c&1){
        tmp*=u;
        if (tmp>=MOD) tmp%=MOD;
    }
    return tmp;
}
vector<int> a,b,c;
bool tim(int n,int m){
    a.clear(),b.clear(),c.clear();
    a.assign(n,0);
    b.assign(m,0);
    c.assign(m,0);
    int tmp;
    bool k;
    for (int start=0;start<MOD;++start){
        a[0]=start;
        tmp=pw(start,MOD-2);
        k=false;
        for (int i=0;i<m;++i){
            if (p[i]){
                if (!start) {k=true;break;}
                b[i]=p[i]*tmp;
                if (b[i]>=MOD) b[i]%=MOD;
            }else b[i]=1;
            c[i]=pw(b[i]?b[i]:MOD,MOD-2);
            if (!c[i]) c[i]=MOD;
        }
        if (k) continue;
        for (int i=1;i<n;++i){
            if (c[0]&&!p[i*m]) {k=true;break;}
            a[i]=p[i*m]*c[0];
            if (a[i]>=MOD) a[i]%=MOD;
            for (int j=1;j<m;++j){
                if (c[j]&&!p[i*m+j]) {k=true;break;}
                if ((p[i*m+j]*c[j])%MOD!=a[i]) {k=true;break;}
            }
            if (k) break;
        }
        if (!k) return true;
    }
    return false;
}
int main(){
    freopen("WEDDING.inp","r",stdin);
    freopen("WEDDING.out","w",stdout);
    scanf("%d%d",&k,&MOD);
    for (int i=0;i<k;++i) scanf("%d",&p[i]);
    int m=round(sqrt(k));
    for (int i=2;i<=m;++i)
    if (k%i==0){
        if (tim(i,k/i)){
            printf("YES\n");
            printf("%d ",i);
            for (int j=0;j<i;++j) printf("%d ",a[j]);
            i=k/i;
            printf("\n%d ",i);
            for (int j=0;j<i;++j) printf("%d ",b[j]);
            return 0;
        }
    }
    printf("NO");
}
