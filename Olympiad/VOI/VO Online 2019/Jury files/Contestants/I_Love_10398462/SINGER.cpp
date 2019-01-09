#include <bits/stdc++.h>

using namespace std;

int x[30],a[30];
int res,n,d,t;

void check(){
    for (int i=1; i<=n; i++)
        a[i]=a[i-1]+x[i];
    priority_queue<int> hmax;
    priority_queue<int, vector<int>, greater<int> > hmin;
    map <int,int> c;
    c.clear();
    while (hmin.size()) hmin.pop();
    while (hmax.size()) hmax.pop();
    for (int i=0; i<d-1; i++)
    {
        hmin.push(a[i]);
        hmax.push(a[i]);
        c[a[i]]++;
    }

    int s=0;

    for (int i=0; i<=n-d+1; i++)
    {
        hmax.push(a[i+d-1]);
        hmin.push(a[i+d-1]);
        c[a[i+d-1]]++;
        while (c[hmin.top()]<=0) hmin.pop();
        while (c[hmax.top()]<=0) hmax.pop();
        int g=hmax.top();
        g=hmin.top();

        s+=int(hmax.top()-hmin.top()<=1);
        c[a[i]]--;
    }
    if (s==t)
        res++;
}

void solve(int i){
    for (int j=-1; j<=1; j++)
    if (j!=0){
        x[i]=j;
        if (i==n)
            check();
        else solve(i+1);
        x[i]=0;
    }
}

int main(){
    freopen("SINGER.inp","r",stdin);
    freopen("SINGER.out","w",stdout);

    scanf("%d %d %d",&n,&d,&t);

    solve(1);

    cout<< res;

    return 0;
}
