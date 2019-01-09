#include <bits/stdc++.h>

using namespace std;

#define fi "singer.inp"
#define fo "singer.out"
#define maxn 2005
#define base 998244353
#define For(i,a,b) for(int i=a;i<=b;i++)
#define X first
#define Y second

int n,d,t;
int x[maxn];
int kq=0;

void lam() {
    int dd=0;
    For(i,0,n-d+1) {
        int minx=1e9,maxx=-1;
        For(j,i,i+d-1) {
            minx=min(minx,x[j]);
            maxx=max(maxx,x[j]);
        }
        if (maxx-minx<=1) dd++;
    }

    if (dd==t) {
            kq=((kq+1) ) % base;
               // cout<<dd<<" ";
    //For(i,0,n) cout<<x[i]<<" ";
    //cout<<"\n";
    }
}

void try1(int i) {
    For(j,0,1) {
        if (i==0) x[i]=0;
        else {
            if (j) {
                x[i]=x[i-1]+1;
            }
            else x[i]=x[i-1]-1;
        }
        if (i==n) lam(); else try1(i+1);
    }
}


int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    cin>>n>>d>>t;
    x[0]=0;
    try1(1);
    cout<<kq;

    return 0;
}
