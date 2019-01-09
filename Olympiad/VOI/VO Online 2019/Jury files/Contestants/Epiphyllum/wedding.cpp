#include <bits/stdc++.h>

using namespace std;

int k,D,p[1000005],b[1000005],a[1000005];

void ck(int pr)
{
    for (int i=0; i<max(pr,k/pr); i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    int dem=-1;
    for (int i=0; i<pr; i++)
        for (int j=0; j<k/pr; j++)
        {
            dem++;
            if (p[dem]==1)
            {
                a[i]=1;
                b[j]=1;
            }
        }
    dem=-1;
    for (int i=0; i<pr; i++)
        for (int j=0; j<k/pr; j++)
            if (p[++dem]==0 && a[i]==1 && b[j]==1) return;

    cout << "YES" << '\n';
    cout << pr << ' ' ;
    for (int i=0; i<pr; i++) cout << a[i] << ' ';
    cout << '\n';
    cout << k/pr << ' ';
    for (int i=0; i<k/pr; i++) cout << b[i] << ' ';
    exit(0);
}

int main()
{
    freopen("wedding.inp","r",stdin);
    freopen("wedding.out","w",stdout);
    cin >> k >> D;
    for (int i=0; i<k; i++) cin >> p[i];
    if (D==2)
    {
        for (int pr=2; pr<=k-1; pr++)
            if(k%pr==0) ck(pr);
        //cout << "NO";
    }
    cout << "NO";

    return 0;
}
