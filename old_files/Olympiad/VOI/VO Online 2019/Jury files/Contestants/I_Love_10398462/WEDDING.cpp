#include <bits/stdc++.h>

using namespace std;

int n,m,k,MOD;
int a[100010],b[100010],p[1000010];
bool ok;

bool check(){
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if ( (a[i]*b[j]-p[i*m+j]+MOD)%MOD!=0 )
                return false;
    return true;
}

bool checkB(int j){
    j-=n;
    if (j<0) return true;
    for (int i=0; i<n; i++)
         if ( (a[i]*b[j]-p[i*m+j]+MOD)%MOD!=0 )
            return false;
    return true;
}

void solve(int i){
    for (int j=0; j<MOD; j++){
        if (i<n)
            a[i]=j;
        else
            b[i-n]=j;
        if (checkB(i)){
            if (i==n+m-1)
                ok=true;
            else solve(i+1);
        }
        if (ok) break;
        if (i<n)
            a[i]=0;
        else
            b[i-n]=0;
    }
}

void sub1(){
    solve(0);
}

void sub2(){
    for (int i=1; i<=k; i++)
        if (p[i]==1){
            a[(i/m)]=1;
            b[(i%m)]=1;
        }
    if (!check()) return;
    ok=true;

}

int main(){
    freopen("WEDDING.inp","r",stdin);
    freopen("WEDDING.out","w",stdout);

    scanf("%d %d",&k,&MOD);

    for (int i=0; i<k; i++)
        scanf("%d",&p[i]);

    ok=false;
    for (n=2; n<=sqrt(k) && !ok; n++)
        if (k%n==0){
            m=k/n;
            if (k<=12) sub1();
            else sub2();
        }

    n--;
    if (!ok) cout<<"NO";
    else{
        cout<<"YES\n";
        cout<<n<<" ";
        for (int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        cout<<m<<" ";
        for (int i=0; i<m; i++)
            cout<<b[i]<<" ";
    }

    return 0;
}
