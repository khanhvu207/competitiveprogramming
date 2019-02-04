#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;
#define nmax 110000

stack<int> st;
int n, pos, sl = 0;
int mark[nmax], kq[nmax], next[nmax], bac[nmax];

void s1(int i, int c, int dem)
{
    int j = c, len = 0;
    do{
        len++;
        j = next[j];
    }while (j != c);                //Do dai toan chu trinh

    do{
        kq[j] = len;
        j = next[j];
    }while (j != c);                //KQ toan chu trinh

    j = i;
    do{
        kq[j] = dem--;
        j = next[j];
    }while (j != c);                //KQ Nhanh den
}

void s2(int i, int c, int dem)
{
    int len = kq[c] + dem;
    int t = i;
    do{
        kq[t] = len--;
        t = next[t];
    }while (t != c);
}

int main()
{
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);

    cin >> n;
    memset(mark,0,sizeof(mark));
    memset(kq,0,sizeof(kq));
    for (int i = 1; i<=n; i++)
    {
        cin >> next[i];
        if (i == next[i]) bac[i] = 0;
        else
        {
            bac[i]++; bac[next[i]]++;
        }
    }

    for (int i = 1; i<=n; i++)
        if (bac[i] == 0) { kq[i] = 1; mark[i] = i;}

    for (int i = 1; i<=n; i++)
        if (mark[i] == 0)
        {
            mark[i] = i;
            int c = next[i], dem = 1;
            while (mark[c] != i && kq[c] == 0)
            {
                mark[c] = i;
                dem++;
                c = next[c];
            }

            if (mark[c] == i) s1(i,c,dem); else s2(i,c,dem);
        }

    int smax = 0, pos = n+1;
    for (int i = 0; i<=n; i++)
        if (kq[i] > smax)
        {
            smax = kq[i];
            pos = i;
        }

    cout << pos << " " << smax << endl;
    return 0;
}
